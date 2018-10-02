#ifndef OUTPUT_H
#define OUTPUT_H
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Output
{
public:
    Output();

    void writeOut(char* argv[], string* words, int numWords, int numExtract);
};

#endif // OUTPUT_H
