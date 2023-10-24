#include <iostream>
using namespace std;

class LinkedList {

	struct Node {
		int data;
		Node* next;

		Node(int data, Node* next) { 
			this->data = data;
			this->next = next;
		}
	};

	Node* head, tail;

public:

	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	
	void print() const {
		Node* current = head;

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	bool search(int x) const {
		Node* current = head;

		while (current != nullptr) {
			if (current->data = x) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void pushFront(int number) {
		Node* newHead = new Node(number, head);
		head = newHead;

		if (tail == nullptr) {
			tail = head;
		}
	}

	void pushBack(int number) {
		if (head == nullptr) {
			head = new Node(number);
			tail = head;
		}
		else {
			tail->next = new Node(number);
			tail = tail->next;
		}
	}

	void insert(int number, int position) {
		if (position == 0) {
			pushFront(number);
			return;
		}
		else if (head == nullptr) {
			return;
		}

		Node* current = head;
		Node* previous = nullptr;

		for (int i = 0; i < position; i++) {
			if (current != nullptr) {
				previous = current;
				current = current->next;
			}
			else {
				return;
			}
		}

		previous->next = new Node(number, current);

		if (tail == previous) {
			tail = previous->next;
		}
	}

	void popFront() {
		Node* temp = head;

		if (head != nullptr) {

			if (head == tail) {
				tail = nullptr;
			}
			head = head->next;
			delete temp;
		}
	}

	void popBack() {
		Node* current;
		Node* previous;
		current = head;

		while (current != tail) {
			previous = current;
			current = current->next;
		}

		tail = previous;
		previous->next = nullptr;
		delete current;
	}

	void remove(int position) {
		if (position == 0) {
			popFront();
			return;
		}
		else if (head == nullptr) {
			return;
		}

		Node* current = head;
		Node* previous = nullptr;

		for (int i = 0; i < position; i++) {
			if (current->next != nullptr) {
				previous = current;
				current = current->next;
			}
			else {
				return;
			}
		}
		previous->next = current->next;
		if (tail == current) {
			tail = previous;
		}
		delete current;
	}

};
