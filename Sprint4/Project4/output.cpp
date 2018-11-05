#include "output.h"
#include <fstream>

using namespace std;

Output::Output()
{

}


void Output::writeOut(char *argv[], AdjacencyList<string> adj, int *distance, int numDist, string *inputT)
{
    int numFirstOut = adj.getSize();
    string* temp = new string[numFirstOut]; //temporary string array to sort LL by alpha
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
                string tempstr = temp[j-1];         //Bubble sort for alpha
                temp[j-1] = temp[j];
                temp[j] = tempstr;
            }

        }

    }


    ofstream fout(argv[4]);     //creating output file
    if(fout.is_open())
    {
        for(int i = 0; i < numFirstOut; i ++)
            fout << temp[i] << " " << adj.findWhereFirstIs(temp[i]).getLen() << endl;
        for(int i = 0; i < numDist ; i++)
        {
            fout << inputT[i] << " " << distance[i] << endl;
        }

    }

    fout.close();
    delete[] distance;
    delete[] inputT;
}
