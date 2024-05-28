
#pragma once
/**
 * @class Node
 * @brief Node class for data structures in LinkedLists
 * 
 */
class Node{

public:

    /**
     * @brief returns the node that comes after this node
     * 
     * @return Node* 
     */
    Node *next() { return right; }
    
    /**
     * @brief return the node that comes before this node
     * 
     * @return Node* 
     */
    Node *prev() { return left; }

    /**
     * @brief setter for node left
     * 
     * @param node node to set left to
     */
    void set_prev(Node *node) { left = node; }

    /**
     * @brief setter for node right
     * 
     * @param node node to set right to
     */
    void set_next(Node *node) { right = node; }

    /**
     * @brief Construct a new Node object
     * 
     * @param val node value
     */
    Node(float val) { value = val; }

    /**
     * @brief Destroy the Node object
     * 
     */
    ~Node(){};

    /**
     * @brief Getter Method for node value
     * 
     * @return float node value
     */
    float val() { return value; }

private:
    /**
     * @brief pointer to the node that comes after this node
     * 
     */
    Node *right = nullptr;
    /**
     * @brief pointer to the node that comes before this one
     * 
     */
    Node *left = nullptr;
    /**
     * @brief This node's value
     * 
     */
    float value;
};
