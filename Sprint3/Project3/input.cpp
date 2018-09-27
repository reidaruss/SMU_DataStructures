#include "input.h"
#include <fstream>
#include <iostream>
using namespace std;
Input::Input()
{

}



void Input::fileIn(char* argv[])
{
    ifstream fin(argv[1]);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }

    //while(getline(fin,str)

}
