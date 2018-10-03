//Reid Russell, Sprint 3, The Sorting Competition
#include <iostream>
#include "input.h"
#include "output.h"

using namespace std;

int main(int argc, char* argv[])
{
    int numWords;                                           //number of words in file
    int numExtract;                                         //number of words to extract

    Input i;
    string* words = i.fileIn(argv, numWords, numExtract);   //read in file and return pointer to array of all words
    i.sort(numWords, words);                                //sort by length then alphabetically

    Output o;
    o.writeOut(argv, words, numExtract);                    //file output
    delete[] words;                                         //deallocate words pointer

    return 0;
}


