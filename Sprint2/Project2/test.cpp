#include "catch.hpp"
#include "dsvector.h"

TEST_CASE("DSVector Class","[vector]")
{
    DSVector<int> v;

    SECTION("test getElement")
    {
        DSVector<int> j;
        j.pushBack(4);
        int t = j.getElement(0);
        REQUIRE(t ==4);

    }
    SECTION("Push Back Test")
    {
        DSVector<int> v;
        v.pushBack(1);
        REQUIRE(v[0] == 1);
    }
    SECTION("Copy Consructor Test")
    {
        DSVector<int> v;
        v.pushBack(5);
        v.pushBack(8);
        v.pushBack(2);
        DSVector<int> v1 = v;
        REQUIRE(v1[0] == 5);
        REQUIRE(v1[1] == 8);
        REQUIRE(v1[2] == 2);


    }
    SECTION("Resize Test")
    {
        DSVector<int> v;
        for(int i = 0; i < 12; i ++)
            v.pushBack(i);

        REQUIRE(v.getSize() == 12);
        REQUIRE(v.getCapacity() == 20);
    }

}
