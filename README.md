//3 užduotis//

Sukūriau Vector klasę, kuri yra pilnavertė alternatyva std::vector konteineriui, t.y. visi fonkciunalumai (Member types, Member functions, Non-member functions). Naudojausi: https://en.cppreference.com/w/cpp/container/vector

**Įsitikinti, ar Vector konteineris veikia (funkcionalumo prasme) lygiai taip, kaip std::vector**

Pasirinkau 5 funkcijas ir stebėjau, ar gauti rezultatai su Vector konteineriu atitinka std::vector rezultatus. Naudojausi: https://en.cppreference.com/w/cpp/container/vector

**MAZ_SIZE():**

``` Vector<char> p;
    Vector<long> q;
 
    locale("C"));
    cout << uppercase
         << "p.max_size() = " << std::dec << p.max_size() << " = 0x"
         << std::hex << p.max_size() << '\n'
         << "q.max_size() = " << std::dec << q.max_size() << " = 0x"
         << std::hex << q.max_size() << '\n';
```

#### (TEISINGAS) OUTPUT:

```
p.max_size() = 9,223,372,036,854,775,807 = 0x7,FFF,FFF,FFF,FFF,FFF
q.max_size() = 1,152,921,504,606,846,975 = 0xFFF,FFF,FFF,FFF,FFF
```
**EMPTY():**

```
    cout << boolalpha;
    vector<int> numbers;
    cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    numbers.push_back(42);
    cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
```

#### (TEISINGAS) OUTPUT:

```
Initially, numbers.empty(): true
After adding elements, numbers.empty(): false
```
**PUSH_BACK():**

```
    Vector<string> letters;
 
    letters.push_back("abc");
    string s{"def"};
    letters.push_back(move(s));
 
    std::cout << "std::vector letters holds: ";
    for (auto&& e : letters)
        cout << quoted(e) << ' ';
 
    cout << "\nMoved-from string s holds: " << quoted(s) << '\n';
```

#### (TEISINGAS) OUTPUT:

```
std::vector letters holds: "abc" "def"
Moved-from string s holds: ""
```
**CAPACITY():**

```
int sz = 100;
    Vector<int> v;
 
    auto cap = v.capacity();
    cout << "Initial size: " << v.size() << ", capacity: " << cap << '\n';
 
    cout << "\nDemonstrate the capacity's growth policy."
            "\nSize:  Capacity:  Ratio:\n" << left;
    while (sz-- > 0)
    {
        v.push_back(sz);
        if (cap != v.capacity())
        {
            cout << setw( 7) << v.size()
                 << setw(11) << v.capacity()
                 << setw(10) << v.capacity() / static_cast<float>(cap) << '\n';
            cap = v.capacity();
        }
    }
 
    cout << "\nFinal size: " << v.size() << ", capacity: " << v.capacity() << '\n';
```

#### (TEISINGAS) OUTPUT:

```
Initial size: 0, capacity: 0
 
Demonstrate the capacity's growth policy.
Size:  Capacity:  Ratio:
1      1          inf
2      2          2
3      4          2
5      8          2
9      16         2
17     32         2
33     64         2
65     128        2
 
Final size: 100, capacity: 128
```
**SWAP():**

```
      Vector<int> alice{1, 2, 3};
    Vector<int> bob{7, 8, 9, 10};
 
    auto print = [](const int& n) { cout << ' ' << n; };
 
    // Print state before swap
    cout << "Alice:";
    for_each(alice.begin(), alice.end(), print);
    cout << "\n" "Bob  :";
    for_each(bob.begin(), bob.end(), print);
    cout << '\n';
 
    cout << "-- SWAP\n";
    swap(alice, bob);
 
    // Print state after swap
    cout << "Alice:";
    for_each(alice.begin(), alice.end(), print);
    cout << "\n" "Bob  :";
    for_each(bob.begin(), bob.end(), print);
    cout << '\n';
```

#### (TEISINGAS) OUTPUT:

```
Alice: 1 2 3
Bob  : 7 8 9 10
-- SWAP
Alice: 7 8 9 10
Bob  : 1 2 3
```


