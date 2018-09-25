#include "output.h"
#include <fstream>
#include <iostream>
#include <string.h>



using namespace std;

Output::Output()
{

}

DSVector<Index> Output::sortWords(DSVector<Index>& v)
{
    string temp;
    for(int i = 1; i < v.getSize(); i ++)
    {
        for(int j = 1; j < v.getSize(); j++)
        {

            if(v[j-1] < v[j])
            {
                //strcpy(temp, v[j-1].getWord());
                temp = v[j-1].getWord();
                v[j-1].setString(v[j].getWord());
                v[j].setString(temp);
            }
        }
    }


    return v;


}

void Output::writeOut(char* argv[], DSVector<Index> v)
{
    ofstream fout(argv[3]); //create output stream object
    if(fout.is_open())
    {

        for(int i = v.getSize(); i > 0; i--)
        {
            v[i].print();
        }

    }
    else
        cout << "Error in file output" << endl;

}
