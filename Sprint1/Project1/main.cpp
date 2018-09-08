// Reid Russell, Program 1, MadLibs

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "word.h"
#include "tweet.h"
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

    //for(int i = 0; i < 240; i++){


        cout << temp[1] << endl;
        cout << temp[1].length() << endl;
        string temp2;
//        istream ss(temp[1]);
//        while(getline(ss,temp2,','))
//            cout << temp2 << endl;



    fin.close();

}


int main()
{
    string str;
    input(str);


    return 0;
}
