#include "input.h"
#include <fstream>
#include <iostream>
using namespace std;
Input::Input()
{

}



void Input::fileIn(char* argv[])
{
    int numWords;
    int numExtract;

    ifstream fin(argv[1]);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }

    fin >> numWords;
    fin >> numExtract;
    string * words = new string[numWords];

    for(int i = 0; i < numWords; i ++)
    {
        fin >> words[i];
    }

    fin.close();
    cout << numWords << endl << numExtract << endl;

    for(int i = 0; i < numWords; i ++)
    {
        cout << words[i] << endl;
    }




}

void Input::sort(int numWords, string * words[])
{

}
