#define CATCH_CONFIG_RUNNER
#include "input.h"
#include "output.h"
#include <iostream>
#include "dsvector.h"
#include "catch.hpp"


using namespace std;

int main(int argc, char* argv[])
{
    cout<<"helllo"<<endl;
    Input* mfile = new Input(argv);
    ifstream fin(argv[1]);
    if(strcmp(argv[1], "-t") ==0)
    {
        return Catch::Session().run();
    }


    DSVector<int> v;
//    v.pushBack(1);
//    v.pushBack(2);
//    v.pushBack(3);
//    v.pushBack(4);
//    v.pushBack(5);
//    v.pushBack(6);
//    v.pushBack(7);
//    v.pushBack(8);
//    v.pushBack(9);
//    v.pushBack(10);
//    v.pushBack(11);

    DSVector<int> t = v;
//    t.pushBack(8);
//    t.pushBack(24);
//    t.pushBack(100);




    cout << t[0] << endl;






    return 0;
}
