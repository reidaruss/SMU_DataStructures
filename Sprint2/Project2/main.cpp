#include <iostream>
#include "dsvector.h"
//#define CATCH_CONFIG_RUNNER
//#include "catch.hpp"


using namespace std;

int main()
{
    cout<<"hello"<<endl;
    DSVector<int> v;
    v.pushBack(5);
    v.pushBack(6);

    DSVector<int> t;
    t.pushBack(8);
    t.pushBack(24);
    t.pushBack(100);




    cout << t[1] << endl;






    return 0;
}
