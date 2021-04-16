#include<iostream>
using namespace std;

template<typename T>
class Queue
{
	int rear;
	int front;
	int capacity;
	int noOfElements;
	T* data;
	void reSize(int newSize);

public:
	Queue();
	~Queue();
	void enQueue(T val);
	T deQueue();
	T getElementAtFront();
	bool isEmpty();
	bool isFull();
	int getNoOfElements();
	int getCapacity();
	void showStructure()
	{
		for (int i = 0, j = front; i < noOfElements; i++)
		{
			cout << data[j];
			if (i == noOfElements - 1)
				cout << "         <-- rear";
			cout << endl;
			j = (j + 1) % capacity;
		}
	}
	Queue(const Queue<T>&);
	Queue<T>& operator = (const Queue<T>&);
};
template<typename T>
Queue<T>::Queue()
{
	rear = front = noOfElements = capacity = 0;
	data = nullptr;
}
template<typename T>
void Queue<T>::reSize(int newSize)
{
	if (newSize <= 0)
	{
		this->~Queue();
		return;
	}
	T* newData = new T[newSize];
	for (int i = 0, j = front, k = front; i < noOfElements; i++)
	{
		newData[k] = data[j];
		k = (k + 1) % newSize;
		j = (j + 1) % capacity;
	}
	this->~Queue();
	capacity = newSize;
	data = newData;
	front = front % capacity;
	rear = rear % capacity;
}
template<typename T>
void Queue<T>::enQueue(T val)
{
	if (capacity == 0)
	{
		capacity++;
		reSize(capacity);
	}
	noOfElements++;
	data[rear] = val;
	if (isFull())
		reSize(capacity * 2);
	rear = (rear + 1) % capacity;
}
template<typename T>
T Queue<T>::deQueue()
{
	if (isEmpty())
	{
		cout << "Stack is empty";
		exit(0);
	}
	else
	{
		int temp = front;
		noOfElements--;
		front = (front + 1) % capacity;
		//	if (noOfElements <= capacity / 4)
		//		reSize(capacity / 2);
		return data[temp];
	}
}
template<typename T>
T Queue<T>::getElementAtFront()
{
	if (isEmpty())
	{
		cout << "Stack is empty";
		exit(0);
	}
	else
		return data[front];
}
template<typename T>
bool Queue<T>::isEmpty()
{
	if (noOfElements == 0)
		return true;
	else
		return false;
}
template<typename T>
bool Queue<T>::isFull()
{
	if (capacity == noOfElements)
		return true;
	else
		return false;
}
template<typename T>
int Queue<T>::getNoOfElements()
{
	return noOfElements;
}
template<typename T>
int Queue<T>::getCapacity()
{
	return capacity;
}
template<typename T>
Queue<T>::~Queue()
{
	if (!data)
		return;
	delete[] data;
	data = nullptr;
}
template<typename T>
Queue<T>::Queue(const Queue<T>& queue)
{
	capacity = queue.capacity;
	noOfElements = queue.noOfElements;
	front = queue.front;
	rear = queue.rear;
	data = new T[capacity];
	for (int i = 0, j = front; i < noOfElements; i++)
	{
		data[j] = queue.data[j];
		j = (j + 1) % capacity;
	}
}
template<typename T>
Queue<T>& Queue<T>::operator = (const Queue<T>& queue)
{
	if (this != &queue)
	{
		delete[] data;
		capacity = queue.capacity;
		noOfElements = queue.noOfElements;
		front = queue.front;
		rear = queue.rear;

		data = new T[capacity];

		for (int i = 0, j = front; i < noOfElements; i++)
		{
			data[j] = queue.data[j];
			j = (j + 1) % capacity;
		}
	}
	return *this;
}

int main()
{
	Queue<double> q1;
	q1.enqueue(1);
	q1.enQueue(1.3);
	q1.enQueue(1.5);
	q1.showStructure();
	q1.deQueue();
	q1.deQueue();
	q1.showStructure();
}
