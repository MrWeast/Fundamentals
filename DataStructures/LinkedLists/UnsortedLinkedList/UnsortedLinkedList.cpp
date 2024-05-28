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

class UnsortedLinkedList{
    public:
        //constrcutor
        UnsortedLinkedList(){}

        //deconstrcutor
        ~UnsortedLinkedList(){
            while (count > 0){
                remove(head->val());
            }
        }

        //insert a value
        void insert(float value){
            //inset at head if empty
            Node* newnode = new Node(value);
            if (head==nullptr){
                head = newnode;
            } else if (tail == nullptr) {  //insert at head->next if tail is empty
                head->set_next(newnode);
                newnode->set_prev(head);
                tail = newnode;
            } else{ //insert at tail
                tail->set_next(newnode);
                newnode->set_prev(tail);
                tail = newnode;

            }
           count++;
        }

        // deletes first occurance of value if it exists in the linked list
        void remove(float value){
            // find value
            Node* node = find(value);
            //if value exists
            if (node!=nullptr && node!=head && node!=tail){
                //adjust linked list
                Node* prev = node->prev();
                Node* next = node->next();

                prev->set_next(next);
                next->set_prev(prev);

                //delete value
                delete (node);
                count--;
            }else if (node!= nullptr && node==head) {
                head = node->next();
                delete (node);
                count--;
            }else if (node!= nullptr && node==tail) {
                tail = node->prev();
                delete (node);
                count--;
            }
        }

        // returns a pointer to the first node with a value of value, otherwise returns nullptr
        Node* find(float value){
            Node* curr = head;

            while (curr != nullptr){
                if (curr->val()==value) {
                    return curr;
                }
                curr = curr->next();
            }
            return curr;
        }

        //prints all values in linked list
        void print(){
            std::cout<< std::endl<< "UnsortedLinkedList is: " <<std::endl;
            if (count > 0){
                Node* curr = head;
                for (int i=0; i<count; i++) {
                    std::cout<< curr->val() << " ";
                    curr = curr->next();
                }
            }
            std::cout<< std::endl;
        }


    private:
        Node* head = nullptr; // first element of linked list
        Node* tail = nullptr; // last element of linked list
        int count = 0; // number of nodes in linked list
};


int main(){

    bool isRunning = true;
    char input; //user keyboard input
    float val;
    UnsortedLinkedList* list = new UnsortedLinkedList();
    //have user enter values
    while (isRunning){

        std::cout << "Enter an option:\n\tq: quit\n\tp: print\n\ti: insert\n\tr: remove\n\tf: find" << std::endl;
        std::cin>> input;
        switch (input) {
            case 'q':
                isRunning = false;
                break;
            case 'p':
                list->print();
                break;
            case 'i':
                std::cout<< "Enter a float to insert: ";
                std::cin>> val;
                std::cout << std::endl;
                list->insert(val);
                break;
            case 'r':
                std::cout<< "Enter a float to remove: ";
                std::cin>> val;
                std::cout << std::endl;
                list->remove(val);
                break;
            case 'f': //block scope for the new input
                std::cout<< "Enter a float to find: ";
                std::cin>> val;
                std::cout << std::endl;
                Node* node = list->find(val);
                if (node != nullptr){
                    std::cout << val << " is in the UnsortedLinkedList" << std::endl;
                }else{
                    std::cout << val << " is not in the UnsortedLinkedList" << std::endl;
                }
                break;
        }
    }

    // clean up
    delete (list);


    return 0;
}