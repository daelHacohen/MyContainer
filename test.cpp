//dael12345@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <stdexcept>

using namespace dael_containers;

TEST_CASE("Basic Container Operations") {
    MyContainer<int> container;
    
    SUBCASE("Add and Size") {
        CHECK(container.size() == 0);
        container.add(5);
        CHECK(container.size() == 1);
        container.add(3);
        container.add(5);
        CHECK(container.size() == 3);
    }
    
    SUBCASE("Remove existing item") {
        container.add(5);
        container.add(3);
        container.add(5);
        container.remove(5);  // Should remove all instances
        CHECK(container.size() == 1);
    }
    
    SUBCASE("Remove non-existing item") {
        container.add(5);
        CHECK_THROWS_AS(container.remove(10), std::runtime_error);
    }
}

TEST_CASE("String Container") {
    MyContainer<std::string> container;
    container.add("hello");
    container.add("world");
    container.add("hello");
    
    CHECK(container.size() == 3);
    container.remove("hello");
    CHECK(container.size() == 1);
}

TEST_CASE("AscendingOrder Iterator") {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    
    std::vector<int> expected = {1, 2, 6, 7, 15};
    std::vector<int> actual;
    
    for (auto it = container.beginAscending(); it != container.endAscending(); ++it) {
        actual.push_back(*it);
    }
    
    CHECK(actual == expected);
}

TEST_CASE("DescendingOrder Iterator") {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    
    std::vector<int> expected = {15, 7, 6, 2, 1};
    std::vector<int> actual;
    
    for (auto it = container.beginDescending(); it != container.endDescending(); ++it) {
        actual.push_back(*it);
    }
    
    CHECK(actual == expected);
}

TEST_CASE("SideCrossOrder Iterator") {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    
    std::vector<int> expected = {1, 15, 2, 7, 6};
    std::vector<int> actual;
    
    for (auto it = container.beginSideCross(); it != container.endSideCross(); ++it) {
        actual.push_back(*it);
    }
    
    CHECK(actual == expected);
}

TEST_CASE("ReverseOrder Iterator") {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    
    std::vector<int> expected = {2, 1, 6, 15, 7};
    std::vector<int> actual;
    
    for (auto it = container.beginReverse(); it != container.endReverse(); ++it) {
        actual.push_back(*it);
    }
    
    CHECK(actual == expected);
}

TEST_CASE("Order Iterator") {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    
    std::vector<int> expected = {7, 15, 6, 1, 2};
    std::vector<int> actual;
    
    for (auto it = container.beginOrder(); it != container.endOrder(); ++it) {
        actual.push_back(*it);
    }
    
    CHECK(actual == expected);
}

TEST_CASE("MiddleOutOrder Iterator") {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    
    std::vector<int> expected = {6, 15, 1, 7, 2};
    std::vector<int> actual;
    
    for (auto it = container.beginMiddleOut(); it != container.endMiddleOut(); ++it) {
        actual.push_back(*it);
    }
    
    CHECK(actual == expected);
}

TEST_CASE("Iterators on empty container") {
    MyContainer<int> empty;

    CHECK(empty.size() == 0);

    SUBCASE("AscendingOrder") {
        auto begin = empty.beginAscending();
        auto end = empty.endAscending();
        CHECK(begin == end);
    }

    SUBCASE("DescendingOrder") {
        auto begin = empty.beginDescending();
        auto end = empty.endDescending();
        CHECK(begin == end);
    }

    SUBCASE("SideCrossOrder") {
        auto begin = empty.beginSideCross();
        auto end = empty.endSideCross();
        CHECK(begin == end);
    }

    SUBCASE("ReverseOrder") {
        auto begin = empty.beginReverse();
        auto end = empty.endReverse();
        CHECK(begin == end);
    }

    SUBCASE("Order") {
        auto begin = empty.beginOrder();
        auto end = empty.endOrder();
        CHECK(begin == end);
    }

    SUBCASE("MiddleOutOrder") {
        auto begin = empty.beginMiddleOut();
        auto end = empty.endMiddleOut();
        CHECK(begin == end);
    }
}

TEST_CASE("Single element container - all iterators") {
    MyContainer<int> single;
    single.add(42);

    std::vector<int> expected = {42};

    CHECK(single.size() == 1);

    SUBCASE("AscendingOrder") {
        std::vector<int> actual;
        for (auto it = single.beginAscending(); it != single.endAscending(); ++it)
            actual.push_back(*it);
        CHECK(actual == expected);
    }

    SUBCASE("DescendingOrder") {
        std::vector<int> actual;
        for (auto it = single.beginDescending(); it != single.endDescending(); ++it)
            actual.push_back(*it);
        CHECK(actual == expected);
    }

    SUBCASE("SideCrossOrder") {
        std::vector<int> actual;
        for (auto it = single.beginSideCross(); it != single.endSideCross(); ++it)
            actual.push_back(*it);
        CHECK(actual == expected);
    }

    SUBCASE("ReverseOrder") {
        std::vector<int> actual;
        for (auto it = single.beginReverse(); it != single.endReverse(); ++it)
            actual.push_back(*it);
        CHECK(actual == expected);
    }

    SUBCASE("Order") {
        std::vector<int> actual;
        for (auto it = single.beginOrder(); it != single.endOrder(); ++it)
            actual.push_back(*it);
        CHECK(actual == expected);
    }

    SUBCASE("MiddleOutOrder") {
        std::vector<int> actual;
        for (auto it = single.beginMiddleOut(); it != single.endMiddleOut(); ++it)
            actual.push_back(*it);
        CHECK(actual == expected);
    }
}

TEST_CASE("Double container") {
    MyContainer<double> container;
    container.add(3.3);
    container.add(1.1);
    container.add(2.2);

    std::vector<double> expected = {1.1, 2.2, 3.3};
    std::vector<double> actual;

    for (auto it = container.beginAscending(); it != container.endAscending(); ++it)
        actual.push_back(*it);

    CHECK(actual == expected);
}

TEST_CASE("Char container") {
    MyContainer<char> container;
    container.add('z');
    container.add('a');
    container.add('m');

    std::vector<char> expected = {'a', 'm', 'z'};
    std::vector<char> actual;

    for (auto it = container.beginAscending(); it != container.endAscending(); ++it)
        actual.push_back(*it);

    CHECK(actual == expected);
}


