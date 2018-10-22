#include "catch.hpp"
#include "linkedlist.h"
#include <string>

using namespace std;

TEST_CASE("Linked List Class","[LinkedList]")
{
    SECTION("Insert Test")
    {
        LinkedList<string> s;
        s.insert("hello");
        s.insert("hello2");
        s.insert("hello3");

        REQUIRE(s[0] == "hello");
        REQUIRE(s[1] == "hello2");
        REQUIRE(s[2] == "hello3");

    }
    SECTION("getLen Test")
    {
        LinkedList<string> s;
        s.insert("hello");
        REQUIRE(s.getLen() == 1);
        s.insert("hello2");
        s.insert("hello3");
        REQUIRE(s.getLen() == 3);
    }
    SECTION("Inset At Test")
    {
        LinkedList<string> s;
        s.insert("hello");
        s.insert("hello2");
        s.insert("hello3");
        s.insertAt(2,"Hello2");
        REQUIRE(s[2] == "Hello2");
        REQUIRE(s[3] == "hello3");
        REQUIRE(s[1] == "hello2");
    }
}
