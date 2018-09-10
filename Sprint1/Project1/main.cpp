// Reid Russell, Program 1, MaddLibs
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "word.h"
#include "tweet.h"
#include "fileread.h"
#include <algorithm>
#include <sstream>
using namespace std;

////vector<string> parse(string s[], char delim, int counter) //reference I used for making each tweet a stringstream obj and then splitting: https://thispointer.com/how-to-split-a-string-in-c/
////{
////    string item;
////    vector<string> splitStr;
////    for(int i = 1; i < counter; i++)
////    {
////        stringstream ss(s[i]);
////       while(getline(ss,item,delim))    //put each element in between ',' in its own index in the vector
////            splitStr.push_back(item);
////    }
////    return splitStr;
////}

//vector<vector<string>> parse(string s[], char delim, int counter) //reference I used for making each tweet a stringstream obj and then splitting: https://thispointer.com/how-to-split-a-string-in-c/
//{
//    string item;
//    vector<vector<string>> splitStr(counter);
//    for(int i = 1; i < counter; i++)
//    {
//        stringstream ss(s[i]);
//       while(getline(ss,item,delim))    //put each element in between ',' in its own index in the vector
//        {

//           splitStr[i].push_back(item);
//        }
//    }
//    return splitStr;
//}





int main(int argc, char* argv[])
{
//    int counter = 0;                                //Number of total tweets in the file, will be filled in input() and used in parse().
//    string str;
//    string temp[400];                               //Where the initial tweets are read in and then parsed in input().
//    input(argv,str, temp, counter);
//    char delim = ',';
//    //vector<string> iTweet = parse(temp,delim, counter);
//    vector<vector<string>> iTweet = parse(temp,delim, counter);



//    for(int i = 0; i < iTweet.size(); i ++){
//        for(int j =0 ; j < iTweet[i].size(); j ++) //remove
//            cout << iTweet[i][j] << endl;
//    }
//    cout << endl << endl << endl << iTweet.size();

    FileRead* file = new FileRead(argv);
    file->parse();


    return 0;
}
