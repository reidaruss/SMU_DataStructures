#include "fileread.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
FileRead::FileRead(char* argv[])
{
    negSent = 0;    //ticker for total  - sentiment
    posSent = 0;    //ticker for total + sentiment
    counter = 0;    //ticker for total.
    string str;
    ifstream fin(argv[1]);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }
    int i = 0;                                      //temporary  counter to increment temp[i] without for loop.
    while(getline(fin,str)){
        temp.push_back(str);
        i++;
        counter ++;                                 //counter is for number of tweets.
   }

   fin.close();

}

void FileRead::parse()
{
    for(int i = 0; i < counter; i++)                //Loop to remove all special characters except ','.
    {
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), '('), temp[i].end() ); //Reference I used to remove specific characters : https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), ')'), temp[i].end() );
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), '['), temp[i].end() );
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), ']'), temp[i].end() );
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), '\''), temp[i].end() );
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), '\"'), temp[i].end() );

    }
    char delim = ',';

        string item;
        vector<string> splitStr(counter);
        for(int i = 0; i < counter; i++)
        {
            stringstream ss(temp[i+1]);   //Reference I used for stringstream use : https://thispointer.com/how-to-split-a-string-in-c/
            while(getline(ss,item,delim)) //put each element in between ',' in its own index in the vector
               {
               splitStr.push_back(item);
               }
        }

    for(int i = 0; i < splitStr.size(); i ++)       //Counting total number of Negative and Positive sentiment tweets.
    {
        if(splitStr[i] == "0")
            negSent++;
        else if(splitStr[i] =="4")
            posSent++;
    }



}


