#include <iostream>

//Раскидать по файлам

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
