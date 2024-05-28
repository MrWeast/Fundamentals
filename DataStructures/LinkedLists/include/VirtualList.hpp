#pragma once
#include "Node.hpp"
#include <string>
/**
 * @class VirtualList
 * @brief This is a virtual class for list polymorphism, all list types will at least have the method in this virtual class
 * 
 */
class VirtualList {
public:
    /**
     * @brief a way to find nodes given a value
     * 
     * @param value find a node with this value
     * @return Node* will return a pointer to the found node or nullptr if not found
     */
    virtual Node* find(float value)=0;
    /**
     * @brief a way to insert new nodes
     * 
     * @param value the value of the new node to insert
     */
    virtual void insert(float value)=0;
    /**
     * @brief a way to remove nodes from the list
     * 
     * @param value remove a node with this value
     */
    virtual void remove(float value)=0;
    /**
     * @brief a way to display the values of all nodes in the list
     * 
     * @return std::string a string containing all node values in list seperated by spaces
     */
    virtual std::string print()=0;
    /**
     * @brief Construct a new Virtual List object
     * 
     */
    VirtualList(){};
    /**
     * @brief Destroy the Virtual List object
     * 
     */
    virtual ~VirtualList()=0; // Define a virtual destructor
};

inline VirtualList::~VirtualList(){}