#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::Node::Node(T value) : data(value), prev(nullptr), next(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    DeleteAll();
}

template <typename T>
void DoublyLinkedList<T>::AddToHead(T value) {
    Node* newNode = new Node(value);
    if (!head) head = tail = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::AddToTail(T value) {
    Node* newNode = new Node(value);
    if (!tail) head = tail = newNode;
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromHead() {
    if (!head) return;
    Node* temp = head;
    if (head == tail) head = tail = nullptr;
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromTail() {
    if (!tail) return;
    Node* temp = tail;
    if (head == tail) head = tail = nullptr;
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAll() {
    while (head) DeleteFromHead();
}

template <typename T>
void DoublyLinkedList<T>::Show() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << '\n';
}

template <typename T>
void DoublyLinkedList<T>::InsertAt(int position, T value) {
    if (position < 0 || position > size) return;
    if (position == 0) {
        AddToHead(value);
        return;
    }
    if (position == size) {
        AddToTail(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* current = head;

    for (int i = 0; i < position; i++)
        current = current->next;

    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAt(int position) {
    if (position < 0 || position >= size) return;
    if (position == 0) {
        DeleteFromHead();
        return;
    }
    if (position == size - 1) {
        DeleteFromTail();
        return;
    }

    Node* current = head;
    for (int i = 0; i < position; i++)
        current = current->next;

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}

template <typename T>
int DoublyLinkedList<T>::Find(T value) const {
    Node* current = head;
    int index = 0;
    while (current) {
        if (current->data == value)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}

template <typename T>
int DoublyLinkedList<T>::FindAndReplace(T oldValue, T newValue) {
    Node* current = head;
    int count = 0;
    while (current) {
        if (current->data == oldValue) {
            current->data = newValue;
            count++;
        }
        current = current->next;
    }
    return count > 0 ? count : -1;
}

template <typename T>
void DoublyLinkedList<T>::Reverse() {
    if (!head) return;

    Node* current = head;
    Node* temp = nullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}
