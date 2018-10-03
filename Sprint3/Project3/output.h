#ifndef OUTPUT_H
#define OUTPUT_H
#include <string>

using namespace std;

class Output
{
public:
    Output();

    void writeOut(char* argv[], string* words, int numExtract); //Output
};

#endif // OUTPUT_H
