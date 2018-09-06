// Reid Russell, Program 1, MadLibs

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;




void input()
{
    fstream fin("ft.csv");
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }
    string str[240];
    string temp;
    for(int i = 0; i < 240; i ++)
    {
        fin >> str[i];
//        istringstream iss(temp);
//        vector<string> v(istream_iterator<string>{iss}, istream_iterator<string>());
//        cout << v[0];
        cout << str[i] << endl;
    }



    fin.close();

}


int main()
{

    input();


    return 0;
}
