#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

template<class T>
class LinkedList
{
private:
    ListNode* head, *tail;
    int length;
    ListNode* curr;

public:
    LinkedList();
    void insert(T val);
    void insertAt(int pos, T val);
    void removeAt(int pos);
    void removeFront();
    void addBack(T val);
    void addFront(T val);


};

template<class T>
class ListNode
{
    template<class U> friend class LinkedList;
private:
    ListNode<T>* next;
    ListNode<T>* prev;
    T payload;
public:
    ListNode(int val);
};

template <typename T>
ListNode::ListNode(int val):next(nullptr),prev(nullptr),data(val){}

void LinkedList::insert(T val)
{
    if(head == nullptr)
    {
        head = new ListNode(val);
        tail = head;
    }
    else
    {
        tail->next = new ListNode(val);
        tail->next->prev = tail;
        tail = tail->next;
    }
}

template <typename T>
void LinkedList::insertAt(int pos, T val)
{
    ListNode* curr = head;
    if(curr == nullptr)
    {
        addFront(val);
        return;
    }
    while(curr->next != nullptr && pos > 0)
    {
        curr = curr->next;
        pos--;
    }
    if(curr == head)
        addFront(val);
    else if(curr == tail)
        addBack(val);
    else
    {
        ListNode* temp = new ListNode(val);
        temp->prev = curr;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
    }
}

void LinkedList::removeAt(int pos)
{
    if(pos >=length)
        throw "Out of range.";
    ListNode* curr = headdd;
    while(pos > 0)
    {
        curr = curr->next;
        pos--;
    }
    if(curr == head)
        removeFront();
    else if(curr == tail)
        removeBack();
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        length--;
    }
}

#endif // LINKEDLIST_H
