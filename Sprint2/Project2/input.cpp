#include "input.h"
#include "dsvector.h"
#include "index.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "output.h"


using namespace std;
Input::Input(char* argv[])
{

    DSVector<Index> temp;       //Each index object has a vector of page numbers and a string for a word
    ifstream fin(argv[2]);
    if(!fin)
    {
        cout << "File cannot be opened." << endl;
    }
    string str = "";            //string to take in each line

    string page;                //string to hold page numbers
    while(getline(fin,str))     //get each line then divide each line up bellow
    {

        int k =0;
        if(str == "<-1>")         //check if the line is the end
            break;
        if(str[0] == '<')         //check for new page
        {
            k = 1;      //Set for newpage line
            string tempstr;
            for(int i = 1; i< str.length(); i++)
            {
                if(str[i] == '>')   //iterate until finds >
                {
                    page = tempstr;
                    break;
                }
                else
                    tempstr += str[i];  //append temporary string until delimeter ">".
            }
        }
        if(k != 1)      //Continue if line is not a new page line.
        {
            for(int i = 0; i < str.length() ; i++)
            {

                if(str[i] == '[')       //looking for phrases
                {
                    string tempstr;
                    for(int j = i+1; j < str.length(); j++)
                    {
                        if(str[j] == ']')   //iterate until closing bracket
                        {
                            for(int k = 0; k < tempstr.length(); k++)       //take out punctuation
                            {
                                if(ispunct(tempstr[k]))
                                {
                                    tempstr.erase(k--,1);
                                }
                            }
                            transform(tempstr.begin(), tempstr.end(), tempstr.begin(),::tolower); //Make lowercase. Used this : https://math-linux.com/c/faq-c/faq-c-stl/article/how-to-convert-string-to-lower-case-or-upper-case-in-c
                            bool tempbool = false;      //set to true if word is already in the vector
                            for(int k = 0; k < temp.getSize(); k++)
                            {
                                if(tempstr == temp[k].getWord())
                                {
                                    tempbool = true;
                                    if(tempbool == true)
                                        temp[k].checkPage(page);
                                }
                            }
                            if(tempbool == false)       //if not create a new object and add the word and page and push it back to the vector
                            {
                                Index index;
                                index.setString(tempstr);
                                index.checkPage(page);
                                temp.pushBack(index);


                            }
                            i = j +1;       //set new i
                            break;
                        }
                        else
                            tempstr += str[j];  //append temporary string until delimeter "]".
                    }
                }
                else
                {
                    string tempstr;
                    for(int j = i; j <= str.length(); j++)
                    {
                        if(str[j] == ' ' || j == str.size()-1)  //delimeter by spaces or end of line.
                        {
                            for(int k = 0; k < tempstr.length(); k++)       //remove punctuation
                            {
                                if(ispunct(tempstr[k]))
                                {
                                    tempstr.erase(k--,1);
                                }
                            }

                            transform(tempstr.begin(), tempstr.end(), tempstr.begin(),::tolower);   //Make lowercase. Used this : https://math-linux.com/c/faq-c/faq-c-stl/article/how-to-convert-string-to-lower-case-or-upper-case-in-c
                            bool tempbool = false;
                            for(int k = 0; k < temp.getSize(); k++)
                            {
                                if(tempstr == temp[k].getWord())
                                {
                                    tempbool = true;
                                    if(tempbool == true)
                                        temp[k].checkPage(page);
                                }

                            }
                            if(tempbool == false)
                            {
                                Index index;
                                index.setString(tempstr);
                                index.checkPage(page);
                                temp.pushBack(index);
                            }

                            i = j;
                            break;
                        }
                        else
                            tempstr += str[j];  //append temp string until delim
                    }
                }
            }
        }


    }

    fin.close();
    for(int i =0; i < temp.getSize(); i ++)
        temp[i].print();
    //Output o;
    //DSVector<Index> sortedV = o.sortWords(temp);
    cout << "SORTED::::::::::::::::::::::::::::::::::::" << endl;
    //for(int i =0; i < sortedV.getSize(); i ++)
        //sortedV[i].print();
    //o.writeOut(argv, temp);
}
