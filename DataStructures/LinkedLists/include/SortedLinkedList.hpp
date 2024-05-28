#pragma once

#include "VirtualList.hpp"
#include "Node.hpp"

class SortedLinkedList: public VirtualList{

public:
    // constrcutor
    SortedLinkedList();

    // deconstrcutor
    ~SortedLinkedList();

    // insert a value
    void insert(float value);

    // deletes first occurance of value if it exists in the linked list
    void remove(float value);

    // returns a pointer to the first node with a value of value, otherwise
    // returns nullptr
    Node* find(float value);

    // prints all values in linked list
    std::string print();

private:
    Node *head = nullptr; // first element of linked list
    int count = 0;        // number of nodes in linked list
};
