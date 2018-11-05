#include "output.h"
#include <fstream>

using namespace std;

Output::Output()
{

}


void Output::writeOut(char *argv[], AdjacencyList<string> adj)
{
    int numFirstOut = adj.getSize();
    string* temp = new string[numFirstOut];
    for(int i = 0; i < numFirstOut; i ++)
    {
        temp[i] = adj.getAt(i,0);
    }
    //SORT ALPHABETICALLY:
    for(int i = 0; i < numFirstOut; i ++)
    {
        for(int j = i +1; j < numFirstOut; j++)
        {
            if(temp[j-1] > temp[j])
            {
                string tempstr = temp[j-1];
                temp[j-1] = temp[j];
                temp[j] = tempstr;
            }

        }

    }
    for(int i = 0; i < numFirstOut; i ++)
        cout << temp[i] << endl;

    //ofstream fout(argv[4]);
    //if(fout.is_open())
    //{

    //}

    //fout.close();
}
