#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "vector.h"

TEST_CASE("Vector operations", "[Vector]") {
    SECTION("Default constructor") {
        Vector<int> vec;
        REQUIRE(vec.size() == 0);
        REQUIRE(vec.capacity() == 0);
        REQUIRE(vec.empty());
    }

    SECTION("Initializer list constructor") {
        Vector<int> vec( {1, 2, 3} ); 
        REQUIRE(vec.size() == 3);
        REQUIRE(vec.capacity() >= 3);
        REQUIRE_FALSE(vec.empty());
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 2);
        REQUIRE(vec[2] == 3);
    }

    SECTION("Copy constructor") {
        Vector<int> vec( {1, 2, 3} ); 
        Vector<int> copy = vec;
        REQUIRE(copy.size() == 3);
        REQUIRE(copy.capacity() >= 3);
        REQUIRE(copy[0] == 1);
        REQUIRE(copy[1] == 2);
        REQUIRE(copy[2] == 3);
    }

    SECTION("Move constructor") {
        Vector<int> vec( {1, 2, 3} ); 
        Vector<int> moved = std::move(vec);
        REQUIRE(moved.size() == 3);
        REQUIRE(moved.capacity() >= 3);
        REQUIRE(vec.size() == 0);
        REQUIRE(vec.capacity() == 0);
    }

    SECTION("Assignment operator") {
        Vector<int> vec( {1, 2, 3} ); 
        Vector<int> assigned;
        assigned = vec;
        REQUIRE(assigned.size() == 3);
        REQUIRE(assigned.capacity() >= 3);
        REQUIRE(assigned[0] == 1);
        REQUIRE(assigned[1] == 2);
        REQUIRE(assigned[2] == 3);
    }

    SECTION("Push back") {
        Vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        REQUIRE(vec.size() == 2);
        REQUIRE(vec.capacity() >= 2);
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 2);
    }

    SECTION("Emplace back") {
        Vector<std::string> vec;
        vec.emplace_back("Hello");
        vec.emplace_back("World");
        REQUIRE(vec.size() == 2);
        REQUIRE(vec.capacity() >= 2);
        REQUIRE(vec[0] == "Hello");
        REQUIRE(vec[1] == "World");
    }

    SECTION("Resize") {
        Vector<int> vec( {1, 2, 3} );
        vec.resize(5);
        REQUIRE(vec.size() == 5);
        REQUIRE(vec.capacity() >= 5);
        REQUIRE(vec[3] == 0);
        REQUIRE(vec[4] == 0);
    }

    SECTION("Erase") {
        Vector<int> vec( {1, 2, 3} ); 
        vec.erase(vec.begin() + 1);
        REQUIRE(vec.size() == 2);
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 3);
    }

}
