template <typename T>

class LinkedList {
public:
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
                head = tail = new Node(val);
            }
            else{
                tail->next = new Node(val, tail);
                tail = tail->next;
            }
            ++size;
        }

        void push_forward(const T& val){
            if (empty()){
                head = tail = new Node(val);
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
            if(!empty()){
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
        bool empty() const{
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
            template<typename Function>
        LinkedList<T> map(Function func) const {
            LinkedList<T> mappedList;
            Node* curNode = head;
            while (curNode != nullptr) {
                mappedList.push_back(func(curNode->data));
                curNode = curNode->next;
            }
            return mappedList;
        }

        template<typename Predicate>
        LinkedList<T> where(Predicate pred) const {
            LinkedList<T> filteredList;
            Node* curNode = head;
            while (curNode != nullptr) {
                if (pred(curNode->data)) {
                    filteredList.push_back(curNode->data);
                }
                curNode = curNode->next;
            }
            return filteredList;
        }

        void insert(const T& elem, size_t index) {
            if (index > size) {
                throw std::out_of_range("Index out of range");
            }
            if (index == 0) {
                push_forward(elem);
                return;
            }
            if (index == size) {
                push_back(elem);
                return;
            }

            Node* current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }

            // Now, current points to the node after which we need to insert the new node
            Node* newNode = new Node(elem, current->prev, current);
            if (current->prev) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
            ++size;
        }

};
