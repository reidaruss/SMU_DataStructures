// Reid Russell, Program 1, MaddLibs
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "word.h"
#include "tweet.h"
#include "fileread.h"
#include "output.h"
#include <algorithm>
#include <sstream>
using namespace std;


int main(int argc, char* argv[])
{

    FileRead* file = new FileRead(argv);
    file->parse();
    Output o;
    o.writeOut(argv, file->counter, file->negSent, file->posSent);
    return 0;
}
