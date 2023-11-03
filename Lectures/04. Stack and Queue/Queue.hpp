#pragma once

template <typename T>
class Queue {
	T* data; // array to store queue elements
	size_t capacity, size;
	size_t front, back; 
public:
	Queue();
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	~Queue();

	T& peek() const; // used to access or modify the next element
	void enqueue(const T&); // add item to the queue
	T dequeue(); //remove item from the queue (first/front/head element)

	size_t getCount() const;
	bool isEmpty() const;
private:
	void resize(const size_t);

	void copyFrom(const Queue<T>&);
	void free();
};

template <typename T>
Queue<T>::Queue() {
	capacity = 4;
	data = new T[capacity];

	size = 0;
	front = back = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other) {
	copyFrom(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
Queue<T>::~Queue() {
	free();
}

template <typename T>
T& Queue<T>::peek() const {
	if (isEmpty()) {
		throw std::exception("The collection is empty!");
	}

	return data[front];
}

template <typename T>
void Queue<T>::enqueue(const T& obj) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	data[back++] = obj;
	back %= capacity;

	size++;
}

template <typename T>
T Queue<T>::dequeue() {
	if (isEmpty()) {
		throw std::exception("The collection is empty!");
	}

	T toReturn = data[front];
	(++front) %= capacity;
	size--;

	return toReturn;
}

template <typename T>
size_t Queue<T>::getCount() const {
	return size;
}

template <typename T>
bool Queue<T>::isEmpty() const {
	return size == 0;
}

template <typename T>
void Queue<T>::resize(const size_t newCapacity) {
	T* newData = new T[newCapacity];

	for (size_t i = 0, ind = front; i < size; i++, (++ind) %= capacity) {
		newData[i] = data[ind];
	}

	free();
	capacity = newCapacity;
	data = newData;

	front = 0;
	back = size;
}

template <typename T>
void Queue<T>::copyFrom(const Queue<T>& other) {
	data = new T[other.capacity];

	for (size_t i = 0; i < other.capacity; i++) {
		data[i] = other.data[i];
	}

	front = other.front;
	back = other.back;

	size = other.size;
	capacity = other.capacity;
}

template <typename T>
void Queue<T>::free() {
	delete[] data;
}