#define CATCH_CONFIG_RUNNER
#include "input.h"
#include "output.h"
#include <iostream>
#include "dsvector.h"
#include "catch.hpp"


using namespace std;

int main(int argc, char* argv[])
{
    cout<<"hello"<<endl;
    Input* mfile = new Input(argv);
    ifstream fin(argv[1]);
    if(strcmp(argv[1], "-t") ==0)
    {
        return Catch::Session().run();
    }


    DSVector<int> v;


    DSVector<int> t = v;





    cout << t[0] << endl;






    return 0;
}
