#pragma once

#include "VirtualList.hpp"
#include "Node.hpp"

/**
 * @class UnsortedLinkedList
 * @brief A linked list that will insert nodes at the end of the list
 * @note inherits from the @ref VirtualList
 * @see VirtualList
 */
class UnsortedLinkedList: public VirtualList{

public:
    /**
     * @brief Construct a new Sorted Linked List object
     * 
     */
    UnsortedLinkedList();

    /**
     * @brief Destroy the Sorted Linked List object
     * 
     */
    ~UnsortedLinkedList();

    /**
     * @brief insert a new node into the list
     * 
     * @param value value of the inserted node
     */
    void insert(float value);

    /**
     * @brief remove the first node with the value 'value' if it exists
     * 
     * @param value value of node to remove
     */
    void remove(float value);

    /**
     * @brief finds the first occurance of a node with value 'value' if it exits
     * 
     * @param value value of the node to find
     * @return Node* returns pointer to the found node if it exits, otherwise returns nullptr
     */
    Node* find(float value);

    /**
     * @brief creates a string containing the values of each node in the list seperated by spaces.
     * 
     * @return std::string the string containing node values
     */
    std::string print();

private:
    /**
     * @brief first element of linked list
     * 
     */
    Node *head = nullptr;

    /**
     * @brief last element of the linked list
     * 
     */
    Node* tail = nullptr;
    /**
     * @brief / number of nodes in linked list
     * 
     */
    int count = 0;
};