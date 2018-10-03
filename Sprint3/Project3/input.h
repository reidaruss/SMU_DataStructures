#ifndef INPUT_H
#define INPUT_H
#include <string>

using namespace std;
class Input
{
public:
    Input();

    string* fileIn(char *argv[],int& numWords, int& numExtract);    //Read in file
    void sort(int numWords, string *words); //sort length and alphabetically
};

#endif // INPUT_H
