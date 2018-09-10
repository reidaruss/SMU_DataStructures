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

    counter = 0;
     //need to change this size to fit any amount.
    string str;
    ifstream fin(argv[1]);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }

    int i = 0;                                      //temporary  counter to increment temp[i] without for loop.
    while(getline(fin,str)){
        temp[i] = str;
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
    //for(int i = 0; i < counter; i++)
        //cout << i << endl << temp[i] << endl;


    char delim = ',';

        string item;
        vector<vector<string>> splitStr(counter);
        for(int i = 0; i < counter; i++)
        {
            stringstream ss(temp[i+1]);

           while(getline(ss,item,delim))    //put each element in between ',' in its own index in the vector
                splitStr[i].push_back(item);
        }

        for(int i = 0; i < splitStr[i].size() ; i ++){
            for(int j = 0; j < splitStr[i][j].size() ; j ++)
                cout<< i << endl << splitStr[i][j] << endl;}

}



