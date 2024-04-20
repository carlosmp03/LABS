#include <iostream>
#include "DynArray.cpp"  // Подключение вашего файла с классом динамического массива

int main() {
    DynArray<int> array1;
    DynArray<int> array2;
    int choice, value, index, arrayChoice;

    while (choice != 9) {
        std::cout << "Choose the option:\n";
        std::cout << "1. add an element to the end\n";
        std::cout << "2. add an element to the start\n";
        std::cout << "3. delete an elem at the end\n";
        std::cout << "4. delete an elem at the start\n";
        std::cout << "5. Insert an elem by index\n";
        std::cout << "6. concatenate two arrays\n";
        std::cout << "7. check if two of the arrays are equal\n";
        std::cout << "8. Show the array\n";
        std::cout << "9. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Choose an array (1 or 2): ";
                std::cin >> arrayChoice;
                std::cout << "Enter the value: ";
                std::cin >> value;
                if (arrayChoice == 1) {
                    array1.push_back(value);
                } else {
                    array2.push_back(value);
                }
                break;
            case 2:
                std::cout << "Choose an array (1 or 2): ";
                std::cin >> arrayChoice;
                std::cout << "Enter the value: ";
                std::cin >> value;
                if (arrayChoice == 1) {
                    array1.push_front(value);
                } else {
                    array2.push_front(value);
                }
                break;
            case 3:
                std::cout << "Choose an array (1 or 2): ";
                std::cin >> arrayChoice;
                if (arrayChoice == 1) {
                    array1.pop_back();
                } else {
                    array2.pop_back();
                }
                break;
            case 4:
                std::cout << "Choose an array (1 or 2): ";
                std::cin >> arrayChoice;
                if (arrayChoice == 1) {
                    array1.pop_front();
                } else {
                    array2.pop_front();
                }
                break;
            case 5:
                std::cout << "Choose an array (1 or 2): ";
                std::cin >> arrayChoice;
                std::cout << "choose the index and the value: ";
                std::cin >> index >> value;
                if (arrayChoice == 1) {
                    array1.insert(value, index);
                } else {
                    array2.insert(value, index);
                }
                break;
            case 6:
                std::cout << "Result of concatenation: ";
                (array1 + array2).print();
                break;
            case 7:
                if (array1 == array2) {
                    std::cout << "Arrays are equal.\n";
                } else {
                    std::cout << "Arrays are not equal.\n";
                }
                break;
            case 8:
                std::cout << "Array 1: ";
                array1.print();
                std::cout << "Array 2: ";
                array2.print();
                break;
            case 9:
                std::cout << "Exiting...\n";
                return 0;  // Выход из программы
            default:
                std::cout << "Wrong choice. Please try again.\n";
                break;
        }
    }
}
