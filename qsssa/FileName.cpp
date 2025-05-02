#include <iostream>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value, Node* ptr = nullptr) : data(value), next(ptr) {}
    };

    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList() {
        DeleteAll();
    }

    void AddToHead(T value) {
        head = new Node(value, head);
    }

    void AddToTail(T value) {
        if (!head) {
            head = new Node(value);
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(value);
    }

    void DeleteFromHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteFromTail() {
        if (!head) return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    void DeleteAll() {
        while (head) {
            DeleteFromHead();
        }
    }

    void Show() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    SinglyLinkedList<int> list;

    list.AddToHead(10);
    list.AddToTail(20);
    list.AddToTail(30);
    list.Show(); // 10 20 30

    list.DeleteFromHead();
    list.Show(); // 20 30

    list.DeleteFromTail();
    list.Show(); // 20

    list.DeleteAll();
    list.Show(); // (ничего не выводится)

    return 0;
}
