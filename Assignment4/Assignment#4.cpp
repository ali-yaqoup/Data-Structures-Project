#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T value;
    Node<T>* prev;
    Node<T>* next;

    Node(T val) : value(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class Deque {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    Deque() : head(nullptr), tail(nullptr), size(0) {}

    ~Deque() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void pushFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void pushBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    T popFront() {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        T value = head->value;
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    T popBack() {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        T value = tail->value;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        return head->value;
    }

    T back() const {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        return tail->value;
    }
};

int main() {
    Deque<int> myDeque;

    // Test pushing and popping from both ends
    myDeque.pushFront(1);
    myDeque.pushFront(2);
    myDeque.pushBack(3);
    myDeque.pushBack(4);

    std::cout << "Front element: " << myDeque.front() << std::endl; // 2
    std::cout << "Back element: " << myDeque.back() << std::endl; // 4

    myDeque.popFront();
    myDeque.popBack();

    std::cout << "Front element after one pop: " << myDeque.front() << std::endl; // 1
    std::cout << "Back element after one pop: " << myDeque.back() << std::endl; // 3

    return 0;
}
