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

    fin >> numWords;    //set number of total words and total number to write out
    fin >> numExtract;
    string * words = new string[numWords];  //declare new array on heap with total amount of words capacity

    for(int i = 0; i < numWords; i ++)
    {
        fin >> words[i];    //read in the words
    }

    fin.close();
    return words;   //return pointer to words array
}

void Input::sort(int numWords, string * words)
{
    string temp;    //temp string to hold words while sorting in place
    for(int i = 1; i < numWords; i ++)  //SORT BY LENGTH
    {
        for(int j = 1; j < numWords; j++)   //bubble sort
        {
            if(words[j-1].length() > words[j].length())
            {
                temp = words[j-1];        //if element to the left is bigger, flip them
                words[j-1] = words[j];
                words[j] = temp;
            }
        }
    }
//::::::::::::::::::::::::::::
    int len = 1;    //Length category for sorting all of same length alphabetically.
    for(int i = 0; i < numWords; i ++)  //SORT ALPHABETICALLY
    {
            int tempi;  //the index of the first element in the next length category
            for(int j = i +1; j <= numWords; j++)
            {
                if(words[j].length() != len)
                {
                    tempi = j;  //find the next index that has a new length and set tempi
                    break;  //once it finds the index of the next length level it breaks out to start alphabetically sorting
                }

            }
            for(int j = i; j < tempi; j ++) //tempi used as upper bound so it only alphabetically sorts the same legth
            {
                for(int k = i+1 ; k < tempi; k++)   //bubble sort again
                {
                        if(words[k-1] > words[k])
                        {
                            temp = words[k-1];        //if element to the left is bigger, flip them
                            words[k-1] = words[k];
                            words[k] = temp;
                        }
                }
            }
            i = tempi -1;   //set new i so it starts back at the first element of the next length level
            len = words[tempi].length();    //sets new length level to check against
    }
}
