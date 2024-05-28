#include <iostream>
#include "../include/SortedLinkedList.hpp"
#include<sstream>

// constrcutor
SortedLinkedList::SortedLinkedList(){}

// deconstrcutor
SortedLinkedList::~SortedLinkedList()
{
    while (count > 0)
    {
        remove(head->val());
    }
}

// insert a value
void SortedLinkedList::insert(float value)
{
    // inset at head if empty
    Node *newnode = new Node(value);
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    { // insert in sorted location
        // if new node <= head
        if (newnode->val() <= head->val())
        {
            head->set_prev(newnode);
            newnode->set_next(head);
            head = newnode;
        }
        else
        {
            Node *curr = head;

            // find node that comes after newnode
            while (curr->next() != nullptr)
            {
                if (newnode->val() > curr->val())
                {
                    curr = curr->next();
                }
                else
                {
                    break;
                }
            }

            // adjust list pointers to insert

            // if end of list
            if (curr->next() == nullptr)
            {
                if (newnode->val() <=
                    curr->val())
                { // if newnode <= last elemt of list
                    newnode->set_next(curr);
                    newnode->set_prev(curr->prev());
                    curr->prev()->set_next(newnode);
                    curr->set_prev(newnode);
                    curr->set_next(nullptr);
                }
                else
                { // if newnode > last element of list
                    curr->set_next(newnode);
                    newnode->set_prev(curr);
                }
            }
            else
            { // if in middle of list
                newnode->set_prev(curr->prev());
                curr->prev()->set_next(newnode);
                newnode->set_next(curr);
                curr->set_prev(newnode);
            }
        }
    }
    count++;
}

// deletes first occurance of value if it exists in the linked list
void SortedLinkedList::remove(float value)
{
    // find value
    Node *node = find(value);
    // if value exists
    if (node != nullptr && node != head)
    {
        // adjust linked list
        Node *prev = node->prev();
        Node *next = node->next();

        prev->set_next(next);
        if (next != nullptr)
        {
            next->set_prev(prev);
        }

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
}

// returns a pointer to the first node with a value of value, otherwise
// returns nullptr
Node* SortedLinkedList::find(float value)
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
std::string SortedLinkedList::print()
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
