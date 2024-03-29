#include <iostream>
#include "DynArray.cpp"

// Overloading input and output operators for DynArray
template<typename T>
std::ostream& operator<<(std::ostream& out, DynArray<T>& arr) {
    out << "[";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        out << arr[i];
        if (i != arr.getSize() - 1)
            out << ", ";
    }
    out << "]";
    return out;
}


template<typename T>
std::istream& operator >> (std::istream& in, DynArray<T>& dar){
    char dummy;
    while (dummy != 'n') { // Compare with character 'n'
        T num;
        std::cin >> num >> dummy;
        dar.push_back(num);
    }
    return in;
}


void PlusOperatorTests(){
    std::cout << "Tests for 2 empty arrays: \n";
    DynArray<int> dar1;
    DynArray<int> dar2;
    DynArray<int> resDar;
    resDar = dar1 + dar2;
    resDar.print();
    std::cout << "Tests for 1 filled and 1 empty array: \n";
    //std::cout << "Enter elements for the array with any ', ' in between spaces(Please put 'n' at the end of the output): \n";
    std::cin >> dar1;
    std::cout << dar1;
    std::cout << "\n";
    std::cout << "Now you can enter your own tests: \n";
    DynArray<int> UsersDar1;
    DynArray<int> UsersDar2;
    DynArray<int> ResForUsers;
    std::cin >> UsersDar1;
    std::cout << "\n";
    std::cin >> UsersDar2;
    std::cout << "\n";
    ResForUsers = UsersDar1 + UsersDar2;
    std::cout << "\n";
    std::cout << ResForUsers;
    std::cout << "\n";
}


float FuncForTest(float x){
    return x * 2;
}

void TestsForMap(){
    DynArray<float> UsersDar;
    std::cout << "Please, enter the elements of the array with ', ' in between elems (put 'n' at the end of the input): \n";
    std::cin >> UsersDar;
    DynArray<float> ResDar = map(UsersDar, FuncForTest);
    std::cout << "\n";
    std::cout << ResDar;
    std::cout << "\n";
}

int main(){
    TestsForMap();
}