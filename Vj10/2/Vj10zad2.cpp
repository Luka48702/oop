#include <iostream>
#include <vector>
#include "Stack.h"

using namespace std;

int main() {

	Stack<int>v;
	Stack<int>v1;

	for (int i = 0; i < 10; i++){
		v.push(i);
	}
	cout << "Pop: " << v.pop() << endl;

	for (int i = 0; i < 12; i++){
		v1.push(i);
	}
	cout << "Pop: " << v1.pop() << endl;


}