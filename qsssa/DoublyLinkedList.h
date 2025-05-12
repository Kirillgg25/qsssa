#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T value);
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void AddToHead(T value);
    void AddToTail(T value);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show() const;

    void InsertAt(int position, T value);
    void DeleteAt(int position);
    int Find(T value) const;
    int FindAndReplace(T oldValue, T newValue);
    void Reverse();
};

#include "DoublyLinkedList.cpp" // подключение реализации

#endif
