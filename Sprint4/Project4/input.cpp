#include "input.h"
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
using namespace std;

Input::Input(char *argv[])
{
    AdjacencyList<string> adj;
    ifstream fin(argv[2]);
    if(!fin)
        cout << "File cannot be opened." << endl;

    string str = "";            //string to take in each line
    int conNum; //first line (number of connections input)
    fin >> conNum;
    string temp[2];
    string temp1 = "";  //temp strings to hold connections of each line.

    int j;

    j = 0;
    for(int i = 0; i < conNum; i ++)
    {
        fin >> str;
        istringstream s(str);
        while(getline(s,temp1,'|'))
        {
            temp[j] = temp1;
            j++;
            if(j == 2)
            {
                adj.insert(temp[0],temp[1]);
                j = 0;
            }
        }
    }


    fin.close();

}
