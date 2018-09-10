#include "output.h"
#include <fstream>
#include <iostream>

using namespace std;
Output::Output()
{

}

void Output::writeOut(char* argv[], int tweetNum, int negSent, int posSent)
{
    ofstream fout(argv[3]);
    if(fout.is_open())
    {
        fout << "Total number of Tweets                   : " << tweetNum << endl;
        fout << "Total number of Negative Sentiment Tweets: " << negSent << endl;
        fout << "Total number of Positive Sentiment Tweets: " << posSent << endl;
        fout.close();
    }
    else
        cout << "Error in file output" << endl;
}
