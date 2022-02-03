// intlist.cpp
// Implements class IntList
// Anna Lee, 2/2/2022

#include "intlist.h"

#include <iostream>
#include <climits>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    first = nullptr;
    Node *p = source.first;
   while (p) {
       append(p->info);
       p = p->next;
   }

    // for (Node *p = source.first; p != NULL; p = p->next) {
    //     append (p->info);
       
    // }
  
    
    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    while (first) {
    Node *n = first;
    first = first->next;
    delete n;
    }
    // delete first;

}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node *n = first;
    while (n) {
        sum+= n->info;
        n = n->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = first;
    while (n) {
        if (n->info == value) {
            return true;
        }
        n = n->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = INT_MIN;
    Node *n = first;
    if (first == 0) {
        return 0;
    }
    while (n) {
     if (n->info > max) {
         max = n->info;
     }   
     n = n->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    
    Node *n = first;
    if (first == 0) {
        return 0;
    }
    
    return sum() / count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    if (first == 0) {
        first = new Node;
        first -> info = value;
        first -> next = 0;
        }
        else {
            Node *n = new Node;
            n -> next = first;
            n-> info = value;
            first = n;
            
        }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){

    Node *p = source.first;

    while (first) {
    Node *n = first;
    first = first->next;
    delete n;
    }
    while (p) {
        append (p->info);
        p = p -> next;

    }
    
    
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
        

    }
    
    
    
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
