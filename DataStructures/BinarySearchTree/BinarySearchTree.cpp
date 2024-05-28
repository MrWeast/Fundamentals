#include <iostream>

class Node{
    public:
        Node* next(){return right;} //returns the node that comes after this node
        Node* prev(){return left;} // return the node that comes before this node
        
        //set the node to point to that comes before this node
        void set_prev(Node* node){
            left = node;
        }

        //set the node to point to that comes after this node
        void set_next(Node* node){
            right = node;
        }
        
        //constructor
        Node(float val){
            value = val;
        }

        //deconstructor
        ~Node(){};

        //return the node value
        float val(){return value;}
    
    private:
        Node* right = nullptr; //pointer to next node
        Node* left= nullptr; //poionter to previous node
        float value; //value of the node
};