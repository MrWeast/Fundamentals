#include <iostream>
#include <sstream>
#include "../include/UnsortedLinkedList.hpp"

// constrcutor
UnsortedLinkedList::UnsortedLinkedList() {}

// deconstrcutor
UnsortedLinkedList::~UnsortedLinkedList()
{
    while (count > 0)
    {
        remove(head->val());
    }
}

// insert a value
void UnsortedLinkedList::insert(float value)
{
    // inset at head if empty
    Node *newnode = new Node(value);
    if (head == nullptr)
    {
        head = newnode;
    }
    else if (tail == nullptr)
    { // insert at head->next if tail is empty
        head->set_next(newnode);
        newnode->set_prev(head);
        tail = newnode;
    }
    else
    { // insert at tail
        tail->set_next(newnode);
        newnode->set_prev(tail);
        tail = newnode;
    }
    count++;
}

// deletes first occurance of value if it exists in the linked list
void UnsortedLinkedList::remove(float value)
{
    // find value
    Node *node = find(value);
    // if value exists
    if (node != nullptr && node != head && node != tail)
    {
        // adjust linked list
        Node *prev = node->prev();
        Node *next = node->next();

        prev->set_next(next);
        next->set_prev(prev);

        // delete value
        delete (node);
        count--;
    }
    else if (node != nullptr && node == head)
    {
        head = node->next();
        delete (node);
        count--;
    }
    else if (node != nullptr && node == tail)
    {
        tail = node->prev();
        delete (node);
        count--;
    }
}

// returns a pointer to the first node with a value of value, otherwise returns nullptr
Node* UnsortedLinkedList::find(float value)
{
    Node *curr = head;

    while (curr != nullptr)
    {
        if (curr->val() == value)
        {
            return curr;
        }
        curr = curr->next();
    }
    return curr;
}

// prints all values in linked list
std::string UnsortedLinkedList::print()
{
    std::ostringstream ss;

    if (count > 0)
    {
        Node *curr = head;
        for (int i = 0; i < count; i++)
        {
            ss << curr->val() << " ";
            curr = curr->next();
        }
    }

    return ss.str();
}



