#include <iostream>

// Включаем вашу реализацию LinkedList
#include "LinkedList.cpp"

// Функция для проверки результата теста
void testResult(const std::string& testName, bool passed) {
    if (passed)
        std::cout << testName << " passed successfully!" << std::endl;
    else
        std::cout << testName << " failed!" << std::endl;
}

// Тест для конструктора LinkedList
void test_constructor() {
    LinkedList<int> list;
    if (list.getSize() == 0 && list.empty())
        testResult("Constructor", true);
    else
        testResult("Constructor", false);
}

// Тест для функции push_back
void test_push_back() {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    std::cout << 1;
    if (list.getSize() == 2){std::cout << 1; testResult("push_back", true); }
    else{std::cout << 1; testResult("push_back", false);}
    
}

// Тест для функции push_forward
void test_push_forward() {
    LinkedList<int> list;
    list.push_forward(1);
    list.push_forward(2);
    if (list.getSize() == 2)
        testResult("push_forward", true);
    else
        testResult("push_forward", false);
}

// Тест для функции pop_back
void test_pop_back() {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    if (list.getSize() == 1)
        testResult("pop_back", true);
    else
        testResult("pop_back", false);
}

// Тест для функции pop_front
void test_pop_front() {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    if (list.getSize() == 1)
        testResult("pop_front", true);
    else
        testResult("pop_front", false);
}

// Тест для функции clear
void test_clear() {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    if (list.getSize() == 0 && list.empty())
        testResult("clear", true);
    else
        testResult("clear", false);
}

// Тест для функции map
void test_map() {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    auto mappedList = list.map([](int x) { return x * 2; });
    if (mappedList.getSize() == 2)
        testResult("map", true);
    else
        testResult("map", false);
}

// Тест для функции where
void test_where() {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto filteredList = list.where([](int x) { return x % 2 == 0; });
    if (filteredList.getSize() == 1)
        testResult("where", true);
    else
        testResult("where", false);
}

int main() {
    test_constructor();
    test_push_back();
    test_push_forward();
    test_pop_back();
    test_pop_front();
    test_clear();
    test_map();
    test_where();

    return 0;
}
