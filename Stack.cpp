#include<iostream>
using namespace std;

template<typename T>
class Stack
{
	T* data;
	int capacity;
	int top;
	void reSize(int newSize)
	{
		T* newData = new T[newSize];
		for (int i = 0; i <= top; i++)
		{
			newData[i] = data[i];
		}
		this->~Stack();
		capacity = newSize;
		data = newData;
	}
public:
	Stack()
	{
		capacity = 0;
		top = -1;
		data = nullptr;
	}
	Stack(int s)
	{
		capacity = s;
		top = -1;
		data = new T[capacity];
	}
	Stack(const Stack<T>& stack)
	{
		capacity = stack.capacity;
		top = stack.top;
		data = new T[capacity];
		for (int i = 0; i <= top; i++)
		{
			data[i] = stack.data[i];
		}
	}
	Stack& operator=(const Stack<T>& stack)
	{
		if (this != &stack) 
		{
			delete[]data;
			capacity = stack.capacity;
			top = stack.top;
			data = new T[capacity];
			for (int i = 0; i <= top; i++)
			{
				data[i] = stack.data[i];
			}
		}
		return *this;
	}
	~Stack()
	{
		if (!data)
			return;
		delete[] data;
		data = nullptr;
	}
	void push(T value)
	{
		if (isFull())
			reSize(capacity==0?1:capacity * 2);
		data[++top] = value;
	}
	T pop()
	{
		if (isEmpty())
			exit(0); //throw exception();

		T val = data[top--];
		if (top  > 0 && top <= capacity / 4)
			reSize(capacity / 2);
		return val;
	}
	int stackTop()
	{
		if (isEmpty())
			exit(0); //throw exception();
		return data[top];
	}
	bool isFull()
	{
		return top == capacity - 1;
	}
	bool isEmpty()
	{
		return top == -1;
	}
	int getCapacity()
	{
		return capacity;
	}
	int getNumberOfElements()
	{
		return top+1;
	}
};