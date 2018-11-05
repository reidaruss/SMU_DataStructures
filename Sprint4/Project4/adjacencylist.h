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
    LinkedList<T> findWhereFirstIs(string val);
    LinkedList<T> stepIterator(string val);
    string getAt(int i, int j);
    int getSize();


};


template <typename T>
AdjacencyList<T>::AdjacencyList()
{
    size = 0;
}

template <typename T>
void AdjacencyList<T>::insert(T find, T val)
{
    bool added1 = false;
    bool added2 = false;
    for(int i = 0; i < size; i ++)
    {
        if(data[i][0] == find)
        {
            data[i].addBack(val);
            added1 = true;
            break;
        }
    }

    if(added1 == false)
    {
        LinkedList<T> temp;
        temp.addBack(find);
        temp.addBack(val);
        data.addBack(temp);
        size++;
    }

    for(int i = 0; i < size; i ++)
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
string AdjacencyList<T>::getAt(int i, int j)
{
    return data[i][j];
}


template <typename T>
LinkedList<T> AdjacencyList<T>::findWhereFirstIs(string val)
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




//LinkedList<string> AdjacencyList::stepIterator(string val)
//{
//    LinkedList<string> L = findWhereFirstIs(val);
//    return L.getNext();
//}
#endif // ADJACENCYLIST_H
