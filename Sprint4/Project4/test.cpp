#include "catch.hpp"
#include "linkedlist.h"
#include "stack.h"
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
    SECTION("clear() Test")
    {
        LinkedList<string> l;
        l.insert("hello");
        l.insert("hello2");
        l.insert("hello3");
        REQUIRE(l.isEmpty() == false);
        l.clear();
        REQUIRE(l.isEmpty() == true);
    }
    SECTION("operator= Test")
    {
        LinkedList<string> l;
        l.insert("hello");
        l.insert("hello2");
        l.insert("hello3");
        LinkedList<string> s;
        s = l;
        REQUIRE(s[0] == "hello");
        REQUIRE(s[1] == "hello2");
        REQUIRE(s[2] == "hello3");
        LinkedList<string> t;
        t.insert("Hello");
        t.insert("Hello2");
        t.insert("Hello3");
        l = t;
        REQUIRE(l[0] == "Hello");
        REQUIRE(l[1] == "Hello2");
        REQUIRE(l[2] == "Hello3");
    }
}

TEST_CASE("Stack Class","[Stack]")
{
    SECTION("Push test")
    {
        Stack s;
        s.push("hello");
        REQUIRE(s[0] == "hello");
        s.push("hello2");
        s.push("hello3");
        REQUIRE(s[1] == "hello2");
        REQUIRE(s[2] == "hello3");

    }

    SECTION("Pop Test")
    {
        Stack s;
        s.push("hello");
        s.push("hello2");
        s.push("hello3");

        REQUIRE(s[2] == "hello3");
        string test = s.pop();
        REQUIRE(test == "hello3");



    }

    SECTION("isEmpty() Test")
    {
        Stack s;
        string temp;
        REQUIRE(s.isEmpty() == true);
        s.push("hello");
        s.push("hello2");
        REQUIRE(s.isEmpty() == false);
        temp = s.pop();
        temp = s.pop();
        REQUIRE(s.isEmpty() == true);
    }

    SECTION("Contains() Test")
    {
        Stack s;
        s.push("hello");
        s.push("hello2");
        REQUIRE(s.contains("hello3") == false);
        REQUIRE(s.contains("hello") == true);
        REQUIRE(s.contains("hello2") == true);
    }

    SECTION("peek() Test")
    {
        Stack s;
        s.push("hello");
        REQUIRE(s.peek() == "hello");
        s.push("hello2");
        REQUIRE(s.peek() == "hello2");
        string temp = s.pop();
        REQUIRE(s.peek() == "hello");

    }

}
