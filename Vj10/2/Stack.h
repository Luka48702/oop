#pragma once
#include<iostream>
using namespace std;

template<typename temp>

class Stack {  //Priv
	temp* arr;
	size_t size;
	size_t cap;

public:
	Stack(size_t cap);
	~Stack() { 
		delete[] arr; 
	}
	void push(const temp& number);
	void print();
	void pop();
	bool isEmpty();
};

template <typename temp>
Stack<temp>::Stack(size_t v)
{
	arr = new int[v];
	size = 0;
	cap = v;
}

template <typename temp>
void Stack<temp>::push(const temp& number) {
	if (size == cap)
	{
		cap *= 2;
		int* myArr = new T[cap];

		for (int i = 0; i < cap - 1; i++)
		{
			myArr[i] = arr[i];
		}

		delete[] arr;
		arr = myArr;
	}

	arr[size] = number;
	++size;
}

template <typename temp>
void Stack<temp>::pop() {
	if (!size) 
		return;
	else {
		--size;
	}
}

template <typename temp>
bool Stack<temp>::isEmpty() {
	return size;
}

template <typename temp>
void Stack<temp>::print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}