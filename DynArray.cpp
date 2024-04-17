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

    void ensureCapacity(size_t minCapacity) {
        if (minCapacity > capacity) {
            size_t newCapacity = capacity * 2 > minCapacity ? capacity * 2 : minCapacity;
            T* newData = new T[newCapacity];
            for (size_t i = 0; i < size; i++) {
                newData[i] = array[i];
            }
            delete[] array;
            array = newData;
            capacity = newCapacity;
        }
    }

public:
    DynArray() : capacity(10), size(0) {
        array = new T[capacity];
    }

    void push_back(const T& elem) {
        if (size == capacity) {
            resize();
        }
        array[size++] = elem;
    }

    void push_front(const T& item) {
        // Shift elements right and insert the item at the beginning
        ensureCapacity(size + 1);
        for (int i = size; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = item;
        size++;
    }

    void insert(const T& item, size_t index) {
        // Insert the item at the given index, shifting elements as necessary
        ensureCapacity(size + 1);
        for (int i = size; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = item;
        size++;
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
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }

    const T& operator[](size_t index) const {
        return array[index];
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

/*

int main() {
    DynArray<int> dar1;
    DynArray<int> dar3;
    dar1.push_back(1);
    dar1.push_back(2);

    DynArray<int> dar2;
    dar2.push_back(3);
    dar2.push_back(4);

    dar1.push_forward(0);
    dar1.print();
    return 0;
}

*/
