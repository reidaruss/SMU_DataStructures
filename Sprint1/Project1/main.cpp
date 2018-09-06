// Reid Russell, Program 1, MadLibs

#include <iostream>
#include <string>
#include <fstream>
using namespace std;




void input(char fileName[], char words[])
{


    fstream fin(fileName);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;

    }

    //number of tweets
    int numString;
    cin >> numString;

    for(int i = 0; i < numString; i ++)
    {

        fin >> words[i];


    }
    for(int i = 0; i < numString; i ++)
    {

        cout << words[i] << endl;
    }

    fin.close();

}


int main()
{
    char fileName[10];
    char words[140];
    input(fileName, words);


    return 0;
}
