#include <iostream>
using namespace std;

const size_t DEFAULT_CAPACITY = 15;

template <typename T>
class Stack {

	T* data;
	size_t capacity;
	int top; // index of the element at top of stack (-1 if stack is empty)

	void resize() {
		int* resizedData = new T[capacity * 2];

		for (size_t i = 0; i < top; i++) {
			resizedData[i] = data[i];
		}

		capacity *= 2;
		delete[] data;
		data = resizedData;
	}

	void moveFrom(Stack&& other) {
		top = other.top;
		capacity = other.capacity;
		data = other.data;
		other.data = nullptr;
		other.top = other.capacity = 0;
	}

	void copyFrom(const Stack& other) {
		data = new T[other.capacity];
		for (size_t i = 0; i < other.top; i++) {
			data[i] = other.data[i];
		}
		top = other.top;
		capacity = other.capacity;
	}

	void free() {
		delete[] data;
	}

public:

	Stack(size_t capacity): capacity(capacity), top(-1) {
		this->data = new T[capacity];
	}

	Stack(): Stack(DEFAULT_CAPACITY) {}

	bool isEmpty() const {
		return top == -1;
	}

	void push(const T& element) {
		if (top >= capacity - 1) {
			resize();
		}

		data[++top] = element;
	}

	void push(T&& element) {
		if (top >= capacity - 1) {
			resize();
		}

		data[++top] = move(element);
	}

	void pop() {
		if (!isEmpty()) {
			top--;
		}
	}

	const T& peek() const {
		if (isEmpty()) {
			return -1;
		}
		return data[top];
	}
};
