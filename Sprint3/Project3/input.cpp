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

            if(words[j-1].length() > words[j].length())
            {

                temp = words[j-1];        //if element to the left is bigger, flip them
                words[j-1] = words[j];
                words[j] = temp;
            }
        }
    }


    int len = 1;    //Length category for sorting all of same length alphabetically.
    for(int i = 0; i < numWords; i ++)
    {


            int tempi;
            for(int j = i +1; j <= numWords; j++)
            {
                if(words[j].length() != len)
                {
                    tempi = j;
                    break;
                }

            }
            for(int j = i; j < tempi; j ++)
            {
                for(int k = i+1 ; k < tempi; k++)
                {
                            if(words[k-1] > words[k])
                            {
                                temp = words[k-1];        //if element to the left is bigger, flip them
                                words[k-1] = words[k];
                                words[k] = temp;

                            }
                }

            }
            i = tempi -1;
            len = words[tempi].length();


    }


}
