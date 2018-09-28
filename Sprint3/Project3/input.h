#ifndef INPUT_H
#define INPUT_H
#include <string>

using namespace std;
class Input
{
public:
    Input();

    void fileIn(char *argv[]);
    void sort(int numWords, string *words[]);
};

#endif // INPUT_H
