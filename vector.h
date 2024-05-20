#pragma once

#include <cstddef> // std::size_t
#include <iterator> // std::reverse_iterator
#include <memory> // std::allocator
#include <initializer_list> // std::initializer_list
#include <algorithm> // std::copy, std::equal

template<typename T, typename Allocator = std::allocator<T>>
class Vector {
private:
    T* m_data;
    std::size_t m_size;
    std::size_t m_capacity;
    Allocator m_alloc;

public:
    // MEMBER TYPES
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = typename std::allocator_traits<Allocator>::size_type;
    using difference_type = typename std::allocator_traits<Allocator>::difference_type;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    //MEMBER FUNCTIONS
    // Constructors
    Vector() : m_data(nullptr), m_size(0), m_capacity(0), m_alloc() {}
    explicit Vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
        : m_size(count), m_capacity(count), m_alloc(alloc) {
        m_data = m_alloc.allocate(m_capacity);
        for (std::size_t i = 0; i < m_size; ++i) {
            m_alloc.construct(&m_data[i], value);
        }
    }
    explicit Vector(std::initializer_list<T> ilist, const Allocator& alloc = Allocator())
        : m_size(ilist.size()), m_capacity(ilist.size()), m_alloc(alloc) {
        m_data = m_alloc.allocate(m_capacity);
        std::copy(ilist.begin(), ilist.end(), m_data);
    }
    ~Vector() {
        clear();
        m_alloc.deallocate(m_data, m_capacity);
    }

    // Copy constructor
    Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_alloc(other.m_alloc) {
        m_data = m_alloc.allocate(m_capacity);
        std::copy(other.begin(), other.end(), m_data);
    }

    // Move constructor
    Vector(Vector&& other) noexcept : m_data(other.m_data), m_size(other.m_size), m_capacity(other.m_capacity), m_alloc(std::move(other.m_alloc)) {
        other.m_data = nullptr;
        other.m_size = other.m_capacity = 0;
    }

    // Operator=
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            clear();
            reserve(other.m_size);
            std::copy(other.begin(), other.end(), begin());
            m_size = other.m_size;
        }
        return *this;
    }
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            clear();
            std::swap(m_data, other.m_data);
            std::swap(m_size, other.m_size);
            std::swap(m_capacity, other.m_capacity);
            std::swap(m_alloc, other.m_alloc);
        }
        return *this;
    }
    // assign
    void assign(size_type count, const T& value) {
        clear();
        reserve(count);
        for (size_type i = 0; i < count; ++i) {
            m_alloc.construct(&m_data[i], value);
        }
        m_size = count;
    }
    void assign(std::initializer_list<T> ilist) {
        assign(ilist.begin(), ilist.end());
    }
    template<typename InputIt>
    void assign(InputIt first, InputIt last) {
        clear();
        reserve(std::distance(first, last));
        std::copy(first, last, m_data);
        m_size = std::distance(first, last);
    }

    // Non-member functions
    friend bool operator==(const Vector& lhs, const Vector& rhs) {
        return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    friend bool operator!=(const Vector& lhs, const Vector& rhs) {
        return !(lhs == rhs);
    }
    friend bool operator<(const Vector& lhs, const Vector& rhs) {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    friend bool operator<=(const Vector& lhs, const Vector& rhs) {
        return !(rhs < lhs);
    }
    friend bool operator>(const Vector& lhs, const Vector& rhs) {
        return rhs < lhs;
    }
    friend bool operator>=(const Vector& lhs, const Vector& rhs) {
        return !(lhs < rhs);
    }

    // Element access
    reference at(size_type pos) {
        if (pos >= m_size) {
            throw std::out_of_range("Vector::at");
        }
        return m_data[pos];
    }
    const_reference at(size_type pos) const {
        if (pos >= m_size) {
            throw std::out_of_range("Vector::at");
        }
        return m_data[pos];
    }
    reference operator[](size_type pos) {
        return m_data[pos];
    }
    const_reference operator[](size_type pos) const {
        return m_data[pos];
    }
    reference front() {
        return m_data[0];
    }
    const_reference front() const {
        return m_data[0];
    }
    reference back() {
        return m_data[m_size - 1];
    }
    const_reference back() const {
        return m_data[m_size - 1];
    }
    T* data() noexcept {
        return m_data;
    }
    const T* data() const noexcept {
        return m_data;
    }

    // Iterators
    iterator begin() noexcept {
        return m_data;
    }
    const_iterator begin() const noexcept {
        return m_data;
    }
    const_iterator cbegin() const noexcept {
        return m_data;
    }
    iterator end() noexcept {
        return m_data + m_size;
    }
    const_iterator end() const noexcept {
        return m_data + m_size;
    }
    const_iterator cend() const noexcept {
        return m_data + m_size;
    }
    reverse_iterator rbegin() noexcept {
        return reverse_iterator(end());
    }
    const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator(end());
    }
    const_reverse_iterator crbegin() const noexcept {
        return const_reverse_iterator(end());
    }
    reverse_iterator rend() noexcept {
        return reverse_iterator(begin());
    }
    const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator(begin());
    }
    const_reverse_iterator crend() const noexcept {
        return const_reverse_iterator(begin());
    }

    // Capacity
    bool empty() const noexcept {
        return m_size == 0;
    }
    size_type size() const noexcept {
        return m_size;
    }
    size_type max_size() const noexcept {
        return std::allocator_traits<Allocator>::max_size(m_alloc);
    }
    void reserve(size_type new_cap) {
        if (new_cap > m_capacity) {
            pointer new_data = m_alloc.allocate(new_cap);
            std::copy(begin(), end(), new_data);
            clear();
            m_data = new_data;
            m_capacity = new_cap;
        }
    }
    size_type capacity() const noexcept {
        return m_capacity;
    }
    void shrink_to_fit() {
        if (m_size < m_capacity) {
            reserve(m_size);
        }
    }

    // Modifiers
    void clear() noexcept {
        for (std::size_t i = 0; i < m_size; ++i) {
            m_alloc.destroy(&m_data[i]);
        }
        m_size = 0;
    }
    iterator insert(const_iterator pos, const T& value) {
        difference_type index = pos - begin();
        if (m_size >= m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        std::move_backward(begin() + index, end(), end() + 1);
        m_alloc.construct(&m_data[index], value);
        ++m_size;
        return begin() + index;
    }
    iterator insert(const_iterator pos, size_type count, const T& value) {
        difference_type index = pos - begin();
        if (count == 0) {
            return begin() + index;
        }
        if (m_size + count > m_capacity) {
            reserve(m_capacity == 0 ? count : m_capacity + count);
        }
        std::move_backward(begin() + index, end(), end() + count);
        for (size_type i = 0; i < count; ++i) {
            m_alloc.construct(&m_data[index + i], value);
        }
        m_size += count;
        return begin() + index;
    }
    template<typename InputIt>
    iterator insert(const_iterator pos, InputIt first, InputIt last) {
        difference_type index = pos - begin();
        difference_type count = std::distance(first, last);
        if (count == 0) {
            return begin() + index;
        }
        if (m_size + count > m_capacity) {
            reserve(m_capacity == 0 ? count : m_capacity + count);
        }
        std::move_backward(begin() + index, end(), end() + count);
        std::copy(first, last, begin() + index);
        m_size += count;
        return begin() + index;
    }
    iterator erase(const_iterator pos) {
        difference_type index = pos - begin();
        m_alloc.destroy(&m_data[index]);
        std::move(begin() + index + 1, end(), begin() + index);
        --m_size;
        return begin() + index;
    }
    iterator erase(const_iterator first, const_iterator last) {
        difference_type index_first = first - begin();
        difference_type index_last = last - begin();
        for (difference_type i = index_first; i < index_last; ++i) {
            m_alloc.destroy(&m_data[i]);
        }
        std::move(begin() + index_last, end(), begin() + index_first);
        m_size -= (index_last - index_first);
        return begin() + index_first;
    }
    void push_back(const T& value) {
        if (m_size >= m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_alloc.construct(&m_data[m_size], value);
        ++m_size;
    }
    void push_back(T&& value) {
        if (m_size >= m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_alloc.construct(&m_data[m_size], std::move(value));
        ++m_size;
    }
    template<typename... Args>
    reference emplace_back(Args&&... args) {
        if (m_size >= m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_alloc.construct(&m_data[m_size], std::forward<Args>(args)...);
        ++m_size;
        return back();
    }
    void pop_back() {
        if (m_size > 0) {
            m_alloc.destroy(&m_data[m_size - 1]);
            --m_size;
        }
    }
    void resize(size_type count) {
        resize(count, T());
    }
    void resize(size_type count, const T& value) {
        if (count < m_size) {
            for (size_type i = count; i < m_size; ++i) {
                m_alloc.destroy(&m_data[i]);
            }
        } else if (count > m_size) {
            if (count > m_capacity) {
                reserve(count);
            }
            for (size_type i = m_size; i < count; ++i) {
                m_alloc.construct(&m_data[i], value);
            }
        }
        m_size = count;
    }
    void swap(Vector& other) noexcept {
        std::swap(m_data, other.m_data);
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
        std::swap(m_alloc, other.m_alloc);
    }
};

