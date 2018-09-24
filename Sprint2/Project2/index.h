#ifndef INDEX_H
#define INDEX_H
#include "dsvector.h"

using namespace std;
template <typename T>
class Index
{
private:
    string s;
    DSVector<int>* pages;
    //DSVector<pair<string,DSVector<int>>> v;
public:
    Index();

    void sort(const DSVector<T>& temp);

};

#endif // INDEX_H
