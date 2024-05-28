#pragma once
#include "Node.hpp"
#include <string>
/**
 * @brief This is a virtual class for list polymorphism when running main.cpp, all list types will at least have each method in this virtual class
 * 
 */
class VirtualList {
public:

    virtual Node* find(float value)=0;
    virtual void insert(float value)=0;
    virtual void remove(float value)=0;
    virtual std::string print()=0;
    VirtualList(){};
    virtual ~VirtualList()=0; // Define a virtual destructor
};

inline VirtualList::~VirtualList(){}