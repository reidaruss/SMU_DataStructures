#include "input.h"
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include "output.h"
using namespace std;

Input::Input(char *argv[])
{
    AdjacencyList<string> adj;
    ifstream fin(argv[2]);
    if(!fin)
        cout << "File cannot be opened." << endl;

    string str = "";            //string to take in each line
    int conNum; //first line (number of connections input)
    fin >> conNum;
    string temp[2];
    string temp1 = "";  //temp strings to hold connections of each line.

    int j;

    j = 0;
    for(int i = 0; i < conNum; i ++)
    {
        fin >> str;
        istringstream s(str);
        while(getline(s,temp1,'|'))
        {
            temp[j] = temp1;
            j++;
            if(j == 2)
            {
                adj.insert(temp[0],temp[1]);
                j = 0;
            }
        }
    }

    fin.close();

    requestedDistanceInput(argv, adj);
    //Output o;   //THIS IS TEMPORARY
    //o.writeOut(argv, adj);
}

//void Input::sepOfTwo(AdjacencyList<string> adj)     //count the number of immediate connections and indirect connects 2 steps away.
//{
//    int imCon[adj.getSize()];
//    Stack s;
//    for(int i = 0; i < adj.getSize(); i++)
//        s.push(adj.getAt(i,0));


//}

void Input::requestedDistanceInput(char* argv[], AdjacencyList<string> &adj)
{
    ifstream fin(argv[3]);
    if(!fin)
        cout << "File cannot be opened." << endl;

    string str = "";
    string temp[2];
    string temp1 = "";
    int disNum; //number of degrees of seperation to process.

    fin >> disNum;
    cout << disNum << endl;
    int* distance = new int[disNum];    //array to hold the degrees of seperation for each line.
    int counter = 0;    //number of degrees of seperation that has been recorded. (used when assigning a new one to distance[counter])
    int j = 0;
    for(int i = 0; i < disNum; i ++)
    {
        fin >> str;
        istringstream s(str);
        while(getline(s,temp1,'|'))
        {
            temp[j] = temp1;
            j++;
            if(j == 2)
            {
                //adj.insert(temp[0],temp[1]);
                requestedDistance(adj, distance, temp, counter);
                j = 0;
                counter++;
            }
        }
    }

    fin.close();

    for(int i = 0; i< disNum; i++)
    {
        cout << distance[i] << endl;
    }


}

void Input::requestedDistance(AdjacencyList<string>& adj, int *numDist, string temp[], int& counter)
{
    Stack s;
    s.push(temp[0]);
    adj.resetIters();
    string nextCheck = "";

    while(!s.isEmpty())
    {
        if(s.peek() == temp[1])     //check to see if the one being saved is smaller than the one already in?
        {
            numDist[counter] = s.getSize()-1;
            s.pop();
        }
        else
        {

           nextCheck = adj.stepIterator(s.peek()); //come back to this
           while(s.contains(nextCheck) && nextCheck != "end")
           {
               nextCheck = adj.stepIterator(s.peek());

           }
           if(nextCheck != "end")
               s.push(nextCheck);
           else
           {
               adj.findWhereFirstIs(s.peek()).resetIterator();
               s.pop();
           }

        }
    }
}
