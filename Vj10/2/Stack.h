#pragma once
#include <vector>
#include <iostream>

using namespace std;

template<typename temp>
class stack {

	temp v;
	int t;

public:
	stack();
	void push(temp v);
	temp pop();
	bool is_empty();
	virtual ~stack();
};

template<typename temp>
stack<temp>::stack() {
	this->v = temp[15];
	t = 0;
}

template<typename X>
stack<X>::~stack() {
	delete[] v;
}

template<typename temp>
void stack<temp>::push(temp number) {
	if (!(t == 11 - 1))
		v[++t] = number;
	else
		cout << "Full" << endl;
}
template<typename temp>
bool stack<temp>::is_empty() {
	if (t == 0)
		return true;
	return false;
}
template <typename temp>
temp stack<temp>::pop()
{
	if (!is_empty())
		return v[t--];
	else
		cout << "Empty" << endl;
}
