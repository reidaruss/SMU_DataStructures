// Reid Russell, Program 1, MaddLibs
#include <iostream>
#include <string>
#include "word.h"
#include "tweet.h"
#include "fileread.h"
#include "output.h"

using namespace std;

int main(int argc, char* argv[])
{

    FileRead* file = new FileRead(argv);        //read in the file
    file->parse();                              //split the tweets up and do some stats
    Output o;
    o.writeOut(argv, file->counter, file->negSent, file->posSent);  //create output file.
    return 0;
}
