#include <iostream>
#include "LinkedList.cpp" 

int main() {
    LinkedList<int> list;
    int choice = -1, value, index;
    while (choice != 9) {
        std::cout << "Choose an option:\n";
        std::cout << "1. Add an element to the end\n";
        std::cout << "2. Add an element to the start\n";
        std::cout << "3. Delete an element at the end\n";
        std::cout << "4. Delete an element at the start\n";
        std::cout << "5. Insert an element by index\n";
        std::cout << "6. Show the list\n";
        std::cout << "7. Show filtered list (only elements greater than a given value)\n";
        std::cout << "8. Apply a function to elements and show\n";
        std::cout << "9. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the value: ";
                std::cin >> value;
                list.push_back(value);
                break;
            case 2:
                std::cout << "Enter the value: ";
                std::cin >> value;
                list.push_forward(value);
                break;
            case 3:
                list.pop_back();
                break;
            case 4:
                list.pop_front();
                break;
            case 5:
                std::cout << "Enter the index and the value: ";
                std::cin >> index >> value;
                list.insert(value, index);
                break;
            case 6:
                std::cout << "List: ";
                list.print();
                break;
            case 7:
                int threshold;
                std::cout << "Enter the threshold value: ";
                std::cin >> threshold;
                list.where([&](int x) { return x > threshold; }).print();
                break;
            case 8:
                std::cout << "Applied function (increment each element): ";
                list.map([](int x) { return x + 1; }).print();
                break;
            case 9:
                std::cout << "Exiting...\n";
                return 0;  // Exit the program
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
