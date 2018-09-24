#include "output.h"
#include <fstream>
#include <iostream>

using namespace std;

Output::Output()
{

}

void Output::writeOut(char* argv[])
{
    ofstream fout(argv[3]); //create output stream object
    if(fout.is_open())
    {

    }
    else
        cout << "Error in file output" << endl;

}
