#include <iostream>
//Linked List
template <typename T>

class LinkedList {
private:
    struct Node{
        T data;
        Node* prev;
        Node* next;
    
    Node(const T& newData, Node* newPrev = nullptr, Node* newNext = nullptr)
        : data(newData), prev(newPrev), next(newNext){}
    };

    Node* head;
    Node* tail;
    size_t size;
    public:
        LinkedList() : head(nullptr), tail(nullptr), size(0) {}
        ~LinkedList() {
            clear();
        }
        void clear(){
            while(head){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            size = 0;
        }
        void push_back(const T& val){
            if (empty()){
                head = new Node(val);
            }
            else{
                tail->next = new Node(val, tail);
                tail = tail->next;
            }
            ++size;
        }
        void push_forward(const T& val){
            if (empty()){
                head = new Node(val);
            }
            else{
                head->prev = new Node(val, head);
                head = head->prev;
            }
            ++size;
        }
        void pop_back(){
            if(!empty()){
                Node* temp = tail;
                tail = tail->prev;
                delete temp;
                if(tail){
                    tail->next = nullptr;
                }
                else{
                    head = nullptr;
                }
                --size;
            }
        }
        void pop_front(){
            if(!empty){
                Node* temp = head;
                head = head->next;
                delete temp;
                if(head){
                    head->prev = nullptr;
                }
                else{
                    tail = nullptr;
                }
                --size;
            }
        }
        size_t getSize() const{
            return size;
        }
        bool empty(){
            return size == 0;
        }
        void print() const{
            Node* curNode = head;
            while(curNode->next != nullptr){
                std::cout << curNode->data << " ";
                curNode = curNode->next;
            }
            std::cout << "\n";
        }
};


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