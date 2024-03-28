#include <iostream>

template<typename T>
class Sequence {
public:
    virtual void append(const T& element) = 0;
    virtual void prepend(const T& element) = 0;
    virtual void insertAt(const T& element, size_t index) = 0;
    virtual void removeAt(size_t index) = 0;
    virtual size_t size() const = 0;
    virtual T& operator[](size_t index) = 0;
    virtual const T& operator[](size_t index) const = 0;
    virtual ~Sequence() {}
};

template<typename T>
class DynamicArraySequence : public Sequence<T> {
private:
    DynamicArray<T> array;

public:
    void append(const T& element) override {
        array.push_back(element);
    }

    void prepend(const T& element) override {
        if (array.getSize() == 0) {
            array.push_back(element);
            return;
        }
        array.push_back(array[array.getSize() - 1]);
        for (size_t i = array.getSize() - 1; i > 0; --i) {
            array[i] = array[i - 1];
        }
        array[0] = element;
    }

    void insertAt(const T& element, size_t index) override {
        if (index >= array.getSize()) {
            append(element);
            return;
        }
        array.push_back(array[array.getSize() - 1]);
        for (size_t i = array.getSize() - 1; i > index; --i) {
            array[i] = array[i - 1];
        }
        array[index] = element;
    }

    void removeAt(size_t index) override {
        if (index >= array.getSize()) {
            return;
        }
        for (size_t i = index; i < array.getSize() - 1; ++i) {
            array[i] = array[i + 1];
        }
        array.pop_back();
    }

    size_t size() const override {
        return array.getSize();
    }

    T& operator[](size_t index) override {
        return array[index];
    }

    const T& operator[](size_t index) const override {
        return array[index];
    }
};