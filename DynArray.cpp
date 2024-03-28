#include <iostream>

template<typename T>
class DynamicArray {
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
    DynamicArray() : capacity(10), size(0) {
        array = new T[capacity];
    }

    ~DynamicArray() {
        delete[] array;
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
};
