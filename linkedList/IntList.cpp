#include <iostream>
// #include <algorithm>
using namespace std;

#include "IntList.h"

IntList::IntList(): head(0), tail(0) {}

IntList::~IntList(){
    while (!empty()) {
        pop_front();
    }
}

void IntList::display() const{
    //cout << "Display called." << endl;
    if(empty()) {
        return;
    }
    else {
        IntNode* currentNode = head;
        // currentNode = head->next;
        cout << currentNode->data;
        while(currentNode->next != 0) {
            currentNode = currentNode->next;
            cout << ' ' << currentNode->data;
        }
    }
    
    //tests head and tail addresses, next, and data;
}

void IntList::push_front(int value){
    
    IntNode* temp = new IntNode(value);
    
    temp->next = head;
    head = temp;
    if(tail == 0) {   //if initially empty node
        tail = temp;
    }
}

void IntList::pop_front(){
    if(empty()) {
        return;
    }
    else {
        IntNode* temp = head;
        head = head->next;
        delete temp;
    }
    if(head == 0) {  //if go to empty node
        tail = 0;
        // cout << "THIS HAPPENS" << endl;
    }
    
}

bool IntList::empty() const{
    if(head == 0 && tail == 0) {
        return true;
    }
    return false;
}


//if list1=list1, that's self assignment, so just do nothing! >:D



IntList::IntList(const IntList &cpy) {
    // if(cpy.empty()) {  
    //     head = 0;
    //     tail = 0;
    // }
    head = 0;
    tail = 0;
    //TODO what if there's only one node????????????
    if(!cpy.empty()) {
        IntNode* curr = cpy.head;
        // cout << endl;
        while(curr != 0) {
            // data = curr->data;
            // next = curr->next;
            push_back(curr->data);
            curr = curr->next;
        }
    }

} 

IntList & IntList::operator=(const IntList &rhs) {
    if (this == &rhs) {
        return *this;
    }
    else if(rhs.empty()) {
        head = 0;
        tail = 0;
    }
    else {
        clear();
        IntNode* curr = rhs.head;
        while(curr != 0) {
            // data = curr->data;
            // next = curr->next;
            push_back(curr->data);
            curr = curr->next;
        }
    }
    return *this;
}

void IntList::push_back(int value) {
    
    IntNode* temp = new IntNode(value);
   
    if (empty()) {
        
        //IntNode* temp = new IntNode(value);
        head = temp;
        tail = temp;
    }
    else {
        
        //IntNode* temp = new IntNode(value);
        tail->next = temp;
        tail = temp;
    }
} 
    
void IntList::clear() {
    while (!empty()) {
        pop_front();
    }
}

void IntList::selection_sort() {
    if (empty()) {
        return;
    }
    else {
        IntNode* min = head;   //CHANGED 0 TO HEAD!!!!!!****!*!!*!*!**!
        int temp = 0;
        for (IntNode* i = head; i->next != 0; i = i->next) {
            min = i;
            for(IntNode* j = i->next; j != 0; j = j->next) {
            
                if (min->data > j->data) {
                    min = j;
                }
            }
            temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }
} 

void IntList::insert_ordered(int value) {//TODO
    if(empty()) {
        push_front(value);
    }
    else if (value <= head->data) { //equal to?????????
        push_front(value);
    }
    else if (value >= tail->data) { //equal to too??????
        push_back(value);
    }
    else {
        IntNode* prev = head;
        IntNode* curr = head->next;
        IntNode* temp = new IntNode(value);
        while(curr != 0) {
            
            if(value < curr->data) {
                prev->next = temp;
                temp->next = curr;
                return;  //break????
            }
            
            prev = prev->next;
            curr = curr->next;
        }
    }
    
}

void IntList::remove_duplicates() { //TODO
    if(empty() || head == tail) {
        return;
    }
    else {
        IntNode* prev = 0;
        // int ite9ration = 0;
        // int jiter = 0;
        for(IntNode* i = head; i != 0; i = i->next) { //FIXME seg fault! maybe issue with the deleting??
            prev = i;
            for(IntNode* j = i->next; j != 0; j = prev->next) {
                
                if(i->data == j->data) {
                    if (j == tail) {
                        delete j; 
                        tail = prev;
                        tail->next = 0;
                        //cout << "tail" << endl;
                        //cout << "j " << j->next << '/' << j->data << endl;
                        if (head == tail) {
                            //cout << "alsdhalsdkh" << endl;
                            return;
                        }
                    }
                    else {
                        prev->next = j->next;
                        delete j;
                        //j = prev->next;    
                        //cout << "match found" << endl;
                    }
                }
                
                
                // if (j == tail && i->data == j->data) { //working with last node, WORKS!! :D (i think) 
                //     delete j; 
                //     tail = prev;
                //     tail->next = 0;
                //     cout << "tail" << endl;
                //     if (head == tail) {
                //         //cout << "alsdhalsdkh" << endl;
                //         return;
                //     }
                //     // else {
                //     //     j = tail;
                //     // }
                // }
                // else if(i->data == j->data) {

                //     prev->next = j->next;
                //     delete j;
                //     //j = prev->next;    
                //     cout << "match found" << endl;
                // }
                else {
                    prev = prev->next;
                }
            }
            cout << "J LOOPed" << endl;
        }
    }
}
    
ostream & operator<<(ostream &out, const IntList &rhs) {
    if(rhs.empty()) {
        return out;
    }
    else {
        IntNode* currentNode = rhs.head;
        // currentNode = head->next;
        out << currentNode->data;
        while(currentNode->next != 0) {
            currentNode = currentNode->next;
            out << ' ' << currentNode->data;
        }
    }
    return out;
}