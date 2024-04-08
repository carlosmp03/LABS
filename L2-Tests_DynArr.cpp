#include <iostream>
#include <cassert>
#include "DynArray.cpp"

// Overloading input and output operators for DynArray
template<typename T>
std::ostream& operator<<(std::ostream& out, DynArray<T>& arr) {
    size_t size = arr.getSize();
    out << "[";
    if (size > 0) {
        for (size_t i = 0; i < size - 1; ++i) {
            out << arr[i] << ", ";
        }
        out << arr[size - 1];
    }
    out << "]";
    return out;
}



template<typename T>
std::istream& operator >> (std::istream& in, DynArray<T>& dar){
    char dummy;
    std::cin.get(dummy); // Считываем первый символ
    if (dummy == 'n') {
        return in; // Если первый символ 'n', возвращаем istream без изменений
    }
    in.putback(dummy); // Возвращаем символ обратно в поток

    while (dummy != 'n') {
        T num;
        std::cin >> num >> dummy;
        dar.push_back(num);
    }
    return in;
}





void test_push_back() {
    DynArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    assert(arr.getSize() == 3);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
}

void test_pop_back() {
    DynArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.pop_back();

    assert(arr.getSize() == 2);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
}

void test_pop_front() {
    DynArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.pop_front();

    assert(arr.getSize() == 2);
    assert(arr[0] == 2);
    assert(arr[1] == 3);
}

void test_operator_index() {
    DynArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
}

void test_operator_plus_equal() {
    DynArray<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    
    DynArray<int> arr2;
    arr2.push_back(3);
    arr2.push_back(4);

    arr1 += arr2;

    assert(arr1.getSize() == 4);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 3);
    assert(arr1[3] == 4);
}

void test_operator_plus() {
    DynArray<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    
    DynArray<int> arr2;
    arr2.push_back(3);
    arr2.push_back(4);

    DynArray<int> result = arr1 + arr2;

    assert(result.getSize() == 4);
    assert(result[0] == 1);
    assert(result[1] == 2);
    assert(result[2] == 3);
    assert(result[3] == 4);
}

void test_operator_equal() {
    DynArray<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);

    DynArray<int> arr2;
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);

    assert(arr1 == arr2);
}

int main() {
    test_push_back();
    test_pop_back();
    test_pop_front();
    test_operator_index();
    test_operator_plus_equal();
    test_operator_plus();
    test_operator_equal();

    std::cout << "All tests passed!\n";

    return 0;
}
