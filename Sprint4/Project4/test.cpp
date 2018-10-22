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
        REQUIRE(s[0] == "hello");

    }
    SECTION("getLen Test")
    {

    }
}
