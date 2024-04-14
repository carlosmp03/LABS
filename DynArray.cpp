#include <iostream>
#include <stdexcept>
#include <algorithm>

template<typename T>
class DynArray {
private:
    T* array;
    size_t capacity;
    size_t size;

    void resize() {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

public:
    DynArray() : capacity(10), size(0) {
        array = new T[capacity];
    }

    void push_back(const T& element) {
        if (size == capacity) {
            resize();
        }
        array[size++] = element;
    }

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    void pop_front() {
        if (size != 0) {
            for (size_t i = 1; i < size; ++i) {
                array[i - 1] = array[i];
            }
            --size;
        }
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }
    

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    DynArray<T>& operator+=(const DynArray<T>& other) {
        size_t newSize = size + other.size;
        if (newSize > capacity) {
            while (newSize > capacity) {
                resize();
            }
        }
        for (size_t i = 0; i < other.size; ++i) {
            array[size + i] = other.array[i];
        }
        size = newSize;
        return *this;
    }

    

    bool operator==(const DynArray<T>& other){
        if(other.size != size){
            return 0;
        }
        for (int i = 0; i < size; i ++){
            if(array[i] != other.array[i]){
                return 0;
            }
        }
        return 1;
    }
    DynArray<T> operator+(const DynArray<T>& arr2) {
        DynArray<T> result;
        size_t newSize = this->getSize() + arr2.getSize();
        if (newSize > result.getCapacity()) {
            while (newSize > result.getCapacity()) {
                result.resize();
            }
        }
        for (size_t i = 0; i < this->getSize(); ++i) {
            result.push_back(array[i]);
        }
        for (size_t i = 0; i < arr2.getSize(); ++i) {
            result.push_back(arr2.array[i]);
        }
        return result;
    }

    void print() const{
        for(int i = 0; i < size; i++){
            std::cout << array[i];
        }
        std::cout << "\n";
    }
};

template<typename T, typename Func>
DynArray<T> map(DynArray<T>& arr, Func func) {
    DynArray<T> result;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        result.push_back(func(arr[i]));
    }
    return result;
}
