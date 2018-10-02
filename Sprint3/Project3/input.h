#ifndef INPUT_H
#define INPUT_H
#include <string>

using namespace std;
class Input
{
public:
    Input();

    string* fileIn(char *argv[],int& numWords, int& numExtract);
    void sort(int numWords, string *words);
};

#endif // INPUT_H
