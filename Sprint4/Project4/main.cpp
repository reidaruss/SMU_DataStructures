//Reid Russell, Program 4, LinkedIn Degrees of Seperation
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "linkedlist.h"
#include "input.h"
#include "adjacencylist.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(strcmp(argv[1], "-r") == 0)
    {
        Input file(argv);
    }

    else if(strcmp(argv[1], "-t") == 0)
    {
        return Catch::Session().run();
    }

    return 0;
}
