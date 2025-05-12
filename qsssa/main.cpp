#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;

    list.AddToHead(3);
    list.AddToTail(5);
    list.AddToHead(1);
    list.Show();

    list.InsertAt(1, 2);
    list.Show();

    list.DeleteAt(2);
    list.Show();

    std::cout << "Found 5 at: " << list.Find(5) << '\n';

    list.FindAndReplace(5, 9);
    list.Show();

    list.Reverse();
    list.Show();

    return 0;
}
