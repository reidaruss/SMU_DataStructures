#include <iostream>
#include "input.h"
#include "output.h"

using namespace std;

int main(int argc, char* argv[])
{
    int numWords;
    int numExtract;
    Input i;
    string* words = i.fileIn(argv, numWords, numExtract);
    i.sort(numWords, words);
    Output o;
    o.writeOut(argv, words, numWords, numExtract);
    delete[] words;

    return 0;
}


