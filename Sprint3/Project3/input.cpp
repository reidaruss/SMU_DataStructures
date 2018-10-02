#include "input.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;
Input::Input()
{

}



string* Input::fileIn(char* argv[], int& numWords, int& numExtract)
{



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
    return words;
}

void Input::sort(int numWords, string * words)
{
    string temp;
    for(int i = 1; i < numWords; i ++)
    {
        for(int j = 1; j < numWords; j++)
        {

            if(words[j-1].length() < words[j].length())
            {

                temp = words[j-1];        //if element to the left is smaller, flip them
                words[j-1] = words[j];
                words[j] = temp;
            }
        }
    }

}
