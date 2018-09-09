// Reid Russell, Program 1, MadLibs

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "word.h"
#include "tweet.h"
#include <algorithm>
#include <sstream>

//need to move parsing to its own function and test the sending and return functions, once complete implement classes.
using namespace std;

vector<string> parse(string s[], char delim) // https://thispointer.com/how-to-split-a-string-in-c/
{
    string item;
    vector<string> splitStr;
    for(int i = 1; i < 240; i++)
    {
        stringstream ss(s[i]);
       while(getline(ss,item,delim))
            splitStr.push_back(item);
    }
    return splitStr;
}


void input(string str, string temp[],int& counter)
{
    string file;
    cout << "Enter file name." << endl;
    cin >> file;
    ifstream fin(file);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }

    int i = 0;
    while(getline(fin,str)){
        temp[i] = str;
        i++;
        counter ++;

   }
    for(int i = 0; i< counter ; i++)
    {
        cout << temp[i] << endl;            //remove
        cout << temp[i].length() << endl;
    }
    for(int i = 0; i < counter; i++)
    {
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), '('), temp[i].end() ); //https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), ')'), temp[i].end() );
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), '['), temp[i].end() );
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), ']'), temp[i].end() );
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), '\''), temp[i].end() );
        temp[i].erase(remove(temp[i].begin(), temp[i].end(), '\"'), temp[i].end() );
        cout << temp[i] << endl;        //remove
    }

    fin.close();
}


int main()
{
    int counter = 0;
    string str;
    string temp[400];
    input(str, temp, counter);
    char delim = ',';
    vector<string> iTweet = parse(temp,delim);

    for(int i = 0; i < iTweet.size(); i ++)     //remove
        cout << iTweet[i] << endl;




    return 0;
}
