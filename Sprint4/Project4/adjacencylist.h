#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include "linkedlist.h"

template<class T>
class AdjacencyList
{
private:
    LinkedList<LinkedList<T>> data;
    int size;
public:

    AdjacencyList();
    void insert(T find, T val);
    LinkedList<T> findWhereFirstIs(string val); //find the linked list associated with a string
    T stepIterator(string val);
    string getAt(int i, int j);
    int getSize();
    void resetIters();
    int getInnerSize(int i);
    string getIter(string val); //get curr
};


template <typename T>
AdjacencyList<T>::AdjacencyList()
{
    size = 0;
}

template <typename T>
void AdjacencyList<T>::insert(T find, T val)
{
    bool added1 = false;    //bool to check if find has been added
    bool added2 = false;    //bool to check if val has been added
    for(int i = 0; i < size; i ++)
    {
        if(data[i][0] == find)
        {
            data[i].addBack(val);   //add back val if find is already there.
            added1 = true;
            break;
        }
    }

    if(added1 == false) //if find has not been found create a new link list push both vals then push to adj list
    {
        LinkedList<T> temp;
        temp.addBack(find);
        temp.addBack(val);
        data.addBack(temp);
        size++;
    }

    for(int i = 0; i < size; i ++)  //everything down here is the same as above just with checks for val then adding find
    {
        if(data[i][0] == val)
        {
            data[i].addBack(find);
            added2 = true;
            break;
        }

    }
    if(added2 == false)
    {
        LinkedList<T> temp;
        temp.addBack(val);
        temp.addBack(find);
        data.addBack(temp);
        size++;
    }

}
template <typename T>
string AdjacencyList<T>::getAt(int i, int j)    //get element at (used in tests)
{
    return data[i][j];
}


template <typename T>
LinkedList<T> AdjacencyList<T>::findWhereFirstIs(string val)    //find where string is and return that linked list
{
    for(int i =0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
            return data[i];
    }
}

template <typename T>
int AdjacencyList<T>::getSize()
{
    return size;
}


template <typename T>
void AdjacencyList<T>::resetIters() //reset all curr to head;
{
    for(int i = 0; i < size; i ++)
    {
        data[i].resetIterator();
    }
}

template <typename T>
string AdjacencyList<T>::getIter(string val)    //get curr
{
    for(int i = 0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
            return data[i].getCurr();
    }


}


template <typename T>
T AdjacencyList<T>::stepIterator(string val)
{
    for(int i =0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
        {
            return data[i].getNext();//sets curr = curr->next and returns curr->payload.
        }
    }





}

template <typename T>
int AdjacencyList<T>::getInnerSize(int i)   //get size of inner ll
{
    return data[i].getLen();
}


#endif // ADJACENCYLIST_H
