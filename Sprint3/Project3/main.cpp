#include <iostream>
#include "input.h"

using namespace std;

int main(int argc, char* argv[])
{
    int numWords;
    int numExtract;
    Input i;
    string* words = i.fileIn(argv, numWords, numExtract);
    i.sort(numWords, words);
    return 0;
}


