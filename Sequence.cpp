#include "DynArray.cpp"
#include "LinkedList.cpp"

template<typename T>
class Sequence {
public:
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;
    virtual int GetLength() const = 0;

    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual Sequence<T>* Concat(const Sequence<T>* list) const = 0;

    virtual ~Sequence() {}
};

template<typename T>
class ArraySequence : public Sequence<T> {
private:
    DynArray<T> array;

public:
    T GetFirst() const override {
        if (array.getSize() == 0) {
            throw std::out_of_range("Index out of range");
        }
        return array[0];
    }

    T GetLast() const override {
        if (array.getSize() == 0) {
            throw std::out_of_range("Index out of range");
        }
        return array[array.getSize() - 1];
    }

    T Get(int index) const override {
        if (index < 0 || index >= array.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || startIndex >= array.getSize() || endIndex < 0 || endIndex >= array.getSize() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        ArraySequence<T>* subsequence = new ArraySequence<T>();
        for (int i = startIndex; i <= endIndex; ++i) {
            subsequence->Append(array[i]);
        }
        return subsequence;
    }

    int GetLength() const override {
        return array.getSize();
    }

    void Append(const T& item) override {
        array.push_back(item);
    }

    void Prepend(const T& item) override {
        DynArray<T> newArray;
        newArray.push_back(item);
        for (size_t i = 0; i < array.getSize(); ++i) {
            newArray.push_back(array[i]);
        }
        array = newArray;
    }

    void InsertAt(const T& item, int index) override {
        if (index < 0 || index > array.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        DynArray<T> newArray;
        for (size_t i = 0; i < index; ++i) {
            newArray.push_back(array[i]);
        }
        newArray.push_back(item);
        for (size_t i = index; i < array.getSize(); ++i) {
            newArray.push_back(array[i]);
        }
        array = newArray;
    }

    Sequence<T>* Concat(const Sequence<T>* list) const override {
        const ArraySequence<T>* arrList = dynamic_cast<const ArraySequence<T>*>(list);
        if (!arrList) {
            throw std::invalid_argument("Cannot concatenate different sequence types");
        }
        ArraySequence<T>* result = new ArraySequence<T>();
        for (size_t i = 0; i < array.getSize(); ++i) {
            result->Append(array[i]);
        }
        for (size_t i = 0; i < arrList->array.getSize(); ++i) {
            result->Append(arrList->array[i]);
        }
        return result;
    }
};

template<typename T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> list;

public:
    T GetFirst() const override {
        if (list.empty()) {
            throw std::out_of_range("Index out of range");
        }
        return list.head->data;
    }

    T GetLast() const override {
        if (list.empty()) {
            throw std::out_of_range("Index out of range");
        }
        return list.tail->data;
    }

    T Get(int index) const override {
        if (index < 0 || static_cast<size_t>(index) >= list.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        typename LinkedList<T>::Node* curNode = list.head;
        for (int i = 0; i < index; ++i) {
            curNode = curNode->next;
        }
        return curNode->data;
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || startIndex >= list.getSize() || endIndex < 0 || endIndex >= list.getSize() || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        ListSequence<T>* subsequence = new ListSequence<T>();
        typename LinkedList<T>::Node* curNode = list.head;
        for (int i = 0; i < startIndex; ++i) {
            curNode = curNode->next;
        }
        for (int i = startIndex; i <= endIndex; ++i) {
            subsequence->Append(curNode->data);
            curNode = curNode->next;
        }
        return subsequence;
    }

    int GetLength() const override {
        return list.getSize();
    }

    void Append(const T& item) override {
        list.push_back(item);
    }

    void Prepend(const T& item) override {
        list.push_forward(item);
    }

    void InsertAt(const T& item, int index) override {
        if (index < 0 || index > list.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        typename LinkedList<T>::Node* curNode = list.head;
        for (int i = 0; i < index; ++i) {
            curNode = curNode->next;
        }
        list.insert(curNode, item);
    }

    Sequence<T>* Concat(const Sequence<T>* other) const override {
        const ListSequence<T>* otherList = dynamic_cast<const ListSequence<T>*>(other);
        if (!otherList) {
            throw std::invalid_argument("Cannot concatenate different sequence types");
        }
        ListSequence<T>* result = new ListSequence<T>();
        typename LinkedList<T>::Node* curNode = list.head;
        while (curNode != nullptr) {
            result->Append(curNode->data);
            curNode = curNode->next;
        }
        curNode = otherList->list.head;
        while (curNode != nullptr) {
            result->Append(curNode->data);
            curNode = curNode->next;
        }
        return result;
    }
};
