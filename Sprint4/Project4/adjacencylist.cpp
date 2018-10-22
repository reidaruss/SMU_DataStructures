#include "adjacencylist.h"

AdjacencyList::AdjacencyList()
{

}

void AdjacencyList::insert(string find, string val)
{
    for(int i = 0; i < data.getLen(); i ++)
    {
        if(data[i][0] == find)
            data[i].addBack(val);
    }
    if(!data.contains(find))
    {
        LinkedList<string> temp;
        temp.addBack(find);
        temp.addBack(val);
        data.addBack(temp);
    }
}



LinkedList<string> AdjacencyList::findWhereFirstIs(string val)
{
    for(int i =0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
            return data[i];
    }
}



//LinkedList<string> AdjacencyList::stepIterator(string val)
//{
//    LinkedList<string> L = findWhereFirstIs(val);
//    return L.getNext();
//}
