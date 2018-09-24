#ifndef INDEX_H
#define INDEX_H
#include "dsvector.h"

using namespace std;
template <typename T>
class Index
{
private:
    //DSVector<pair<string,DSVector<int>>> v;
public:


    void parse(const DSVector<T> &temp);
    void sort();
};

#endif // INDEX_H
