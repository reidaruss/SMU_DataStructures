#include "output.h"
#include <fstream>
#include <iostream>

using namespace std;
Output::Output()
{

}

void Output::writeOut(char* argv[], int tweetNum)
{
    ofstream fout(argv[3]);
    if(fout.is_open())
    {
        fout << "Total Tweets: " << tweetNum << endl;
        fout.close();
    }
    else
        cout << "Error in file output" << endl;
}
