// Reid Russell, Program 1, MadLibs

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "word.h"
#include "tweet.h"
#include <algorithm>
using namespace std;




void input(string str)
{
    string file;
    cout << "Enter file name." << endl;
    cin >> file;
    ifstream fin(file);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }
    string temp[240];
    int i = 0;
    while(getline(fin,str)){
        temp[i] = str;
        i++;


   }
    cout << temp[1] << endl;
    cout << temp[1].length() << endl;


    temp[1].erase(remove(temp[1].begin(), temp[1].end(), '('), temp[1].end() );
    temp[1].erase(remove(temp[1].begin(), temp[1].end(), ')'), temp[1].end() );
    temp[1].erase(remove(temp[1].begin(), temp[1].end(), '['), temp[1].end() );
    temp[1].erase(remove(temp[1].begin(), temp[1].end(), ']'), temp[1].end() );
    //temp[1].erase(remove(temp[1].begin(), temp[1].end(), "'"), temp[1].end() );


    cout << temp[1] << endl;
    fin.close();

}


int main()
{
    string str;
    input(str);


    return 0;
}
