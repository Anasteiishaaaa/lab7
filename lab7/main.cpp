#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {

    try {
        std::cout << "--- 1. Singly Linked List ---\n";
        SinglyLinkedList<int> sList;

        std::cout << "Is empty initially? " << (sList.isEmpty() ? "Yes" : "No") << "\n";

        sList.push_back(10);
        sList.push_front(5);
        sList.push_back(20);
        sList.insert_at(1, 15);

        std::cout << "List: " << sList << "\n";
        std::cout << "Size: " << sList.size() << "\n";

        std::cout << "Find '10': Index " << sList.find(10) << "\n";
        std::cout << "Find '99' (not exists): Index " << sList.find(99) << "\n";

        sList.remove_at(1);
        std::cout << "After removing index 1: " << sList << "\n";

		int removedFront = sList.pop_front();
		std::cout << "Popped front element: " << removedFront << "\n";
        std::cout << "After pop_front: " << sList << "\n";

		int removedBack = sList.pop_back();
		std::cout << "Popped back element: " << removedBack << "\n";
        std::cout << "After pop_back: " << sList << "\n";

        int removedLast = sList.pop_back();
		std::cout << "Popped last element: " << removedLast << "\n";
        std::cout << "After removing last element: " << sList << " (Size: " << sList.size() << ")\n\n";


        std::cout << "--- 2. Doubly Linked List ---\n";
        DoublyLinkedList<std::string> dList;

        dList.push_back("Apple");
        dList.push_front("Banana");
        dList.push_back("Cherry");
        dList.insert_at(2, "Orange");

        std::cout << "List: " << dList << "\n";
        std::cout << "Element at index 2: " << dList.at(2) << "\n";

        dList.insert_at(0, "Mango");
        std::cout << "After insert_at(0): " << dList << "\n";

        dList.remove_at(4);
        std::cout << "After remove_at(last_index): " << dList << "\n";

		std::cout << "Popped from back: " << dList.pop_front() << "\n";
        std::cout << "Popped from front: " << dList.pop_front() << "\n";
        std::cout << "After pop_back and pop_front: " << dList << "\n\n";

        std::cout << "--- 3. Exceptions Testing (Negative Scenarios) ---\n";
        std::cout << "Trying to access index 100 in dList...\n";
        dList.at(100);

    }
    catch (const std::out_of_range& e) {
        std::cerr << "[EXCEPTION] Out of range: " << e.what() << "\n";
    }
    catch (const std::runtime_error& e) {
        std::cerr << "[EXCEPTION] Runtime error: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "[EXCEPTION] " << e.what() << "\n";
    }

    try {
        std::cout << "\nTrying to pop_front from an empty list...\n";
        SinglyLinkedList<double> emptyList;
        emptyList.pop_front();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "[EXCEPTION] Runtime error: " << e.what() << "\n";
    }

    return 0;
}