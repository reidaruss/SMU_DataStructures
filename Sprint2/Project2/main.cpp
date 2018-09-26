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
    Input* mfile = new Input(argv); //Create new input object
    if(strcmp(argv[1], "-t") ==0)   //run tests if -t
    {
        return Catch::Session().run();
    }

    delete[] mfile; //Free up mfile heap memory
    return 0;
}
