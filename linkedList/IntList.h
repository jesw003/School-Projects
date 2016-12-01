#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

class IntList {
    IntNode* head;
    IntNode* tail;
 public:
    IntList();
    ~IntList();
    void display() const;
    void push_front(int value);
    void pop_front();
    bool empty() const;
    IntList(const IntList &cpy); //the copy constructor.
    IntList & operator=(const IntList &rhs); //the overloaded assignment operator.
    void push_back(int value);  //Inserts a data value (within a new node) at the back end of the list.
    void clear(); //Removes (deallocates) all IntNodes in the IntList.
    void selection_sort(); //Sorts the integers in the list into ascending order.
    void insert_ordered(int value); //Inserts a data value (within a new node) in an ordered list.
    void remove_duplicates(); //Removes all duplicate data values (actually removes the nodes that contain the values) within the list.
    friend ostream & operator<<(ostream &out, const IntList &rhs);  //A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. the end.
};



#endif