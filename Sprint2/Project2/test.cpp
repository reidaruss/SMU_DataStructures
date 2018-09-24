#include "catch.hpp"
#include "dsvector.h"

TEST_CASE("DSVector Class","[vector]")
{
    DSVector<int> v;

    SECTION("test getElement")
    {
        DSVector<int> j;
        j.pushBack(4);
        int t = j.getElement(4);
        REQUIRE(t ==0);

    }


}
