#ifndef FILEREAD_H
#define FILEREAD_H
#include <string>

using namespace std;
class FileRead
{
private:
    int counter;
    string temp[400];
public:
    FileRead(char *argv[]);

    void parse();
};

#endif // FILEREAD_H
