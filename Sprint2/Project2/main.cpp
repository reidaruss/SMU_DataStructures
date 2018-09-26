#define CATCH_CONFIG_RUNNER
#include "input.h"
#include "output.h"
#include <iostream>
#include "dsvector.h"
#include "catch.hpp"
#include "index.h"


using namespace std;

int main(int argc, char* argv[])
{

    Input* mfile = new Input(argv);
    ifstream fin(argv[1]);
    if(strcmp(argv[1], "-t") ==0)
    {
        return Catch::Session().run();
    }

    delete[] mfile;
    return 0;
}
