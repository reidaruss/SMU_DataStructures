#ifndef FILEREAD_H
#define FILEREAD_H
#include <string>
#include <vector>

using namespace std;
class FileRead
{
private:

    vector<string> temp;
public:
    int counter;
    FileRead(char *argv[]);

    void parse();
};

#endif // FILEREAD_H
