#include <iostream>
#include "../include/UnsortedLinkedList.hpp"
#include "../include/SortedLinkedList.hpp"
#include "../include/VirtualList.hpp"

int main()
{

    bool isRunning = true;
    char input; // user keyboard input
    float val;
    bool isStructure = false; //true if a data strucutre is chosen
    VirtualList* list;

    while (!isStructure){
        std::cout << "Enter an option for a data strcuture to test:\n\t1: UnsortedLinkedList\n\t2: SortedLinkedList" << std::endl;
        std::cin >> input;
        switch (input) {
            case '1':
                list = new UnsortedLinkedList();
                isStructure = true;
                break;
            case '2':
                list = new SortedLinkedList();
                isStructure = true;
                break;

        }
    }


    // have user enter values
    while (isRunning)
    {

        std::cout << "Enter an option:\n\tq: quit\n\tp: print\n\ti: insert\n\tr: remove\n\tf: find" << std::endl;
        std::cin >> input;
        switch (input)
        {
        case 'q':
            isRunning = false;
            break;
        case 'p':
            std::cout << std::endl << "List: " << list->print() << std::endl << std::endl;
            break;
        case 'i':
            std::cout << "Enter a float to insert: ";
            std::cin >> val;
            std::cout << std::endl;
            list->insert(val);
            break;
        case 'r':
            std::cout << "Enter a float to remove: ";
            std::cin >> val;
            std::cout << std::endl;
            list->remove(val);
            break;
        case 'f': // block scope for the new input
            std::cout << "Enter a float to find: ";
            std::cin >> val;
            std::cout << std::endl;
            Node *node = list->find(val);
            if (node != nullptr)
            {
                std::cout << std::endl << val << " is in the list" << std::endl << std::endl;
            }
            else
            {
                std::cout << std::endl << val << " is not in the list" << std::endl << std::endl;
            }
            break;
        }
    }

    // clean up
    delete (list);

    return 0;
}