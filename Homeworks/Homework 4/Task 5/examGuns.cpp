#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class DoublyLinkedList
{
    struct Node {
        T data;
        Node* previous = nullptr;
        Node* next = nullptr;
    };

    Node* head;
    Node* tail;
    Node* mid;
    size_t size;

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr), mid(nullptr), size(0) {}
    ~DoublyLinkedList() {
        if (size == 0) {
            return;
        }
        Node* temp;
        for (Node* node = head->next; node != nullptr;) {
            temp = node->next;
            delete node;
            node = temp;
        }
    }

    void push_back(T data) {
        tail = (tail == nullptr ? head : tail->next) = new Node{ data, tail };
        mid = (++size == 2 ? head : size % 2 == 0 ? mid->next : mid);
    }

    void pop_back() {
        if (tail == head) {
            delete tail;
            tail = head = nullptr;
        }
        else {
            Node* beforeLast = tail->previous;
            delete tail;
            (tail = beforeLast)->next = nullptr;
        }
        if (--size % 2 && mid != nullptr) {
            mid = mid->previous;
        }
    }

    const Node* getMid() const { return mid; }

    void switchMid() {
        if (mid == nullptr) {
            return;
        }
        (tail->next = head)->previous = tail;
        mid->next = (head = mid->next)->previous = nullptr;
        swap(mid, tail);
        if (size % 2) {
            mid = mid->previous;
        }
    }

    void printOutput() const {
        cout << size << endl;
        for (Node* node = head; node != nullptr; node = node->next) {
            cout << node->data << ' ';
        }
    }
};

int main()
{
    DoublyLinkedList<size_t> guns;

    size_t queriesAmount;
    cin >> queriesAmount;
    for (size_t i = 0; i < queriesAmount; i++) {
        string query;
        cin >> query;
        if (query == "add") {
            int x;
            cin >> x;
            guns.push_back(x);
        }
        else if (query == "gun") {
            guns.pop_back();
        }
        else {
            guns.switchMid();
        }
    }
    guns.printOutput();
    return 0;
}
