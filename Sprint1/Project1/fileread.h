#ifndef FILEREAD_H
#define FILEREAD_H
#include <string>

using namespace std;
class FileRead
{
private:

    string temp[400];
public:
    int counter;
    FileRead(char *argv[]);

    void parse();
};

#endif // FILEREAD_H
