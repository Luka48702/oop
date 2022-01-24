#include <iostream>

using namespace std;

template<typename temp> //tip->funk

void sort(temp *a) { 
	for (int i = 0; i < strlen(a); i++) {
		for(int j = 0; j < strlen(a); j++)
			if (a[i] < a[j]) {
				temp c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
	}
}

template<typename temp>
void print(temp* a) {
	for (int i = 0; i < strlen(a); i++) {
		cout << a[i];
	}
}

void main() {
	char arr[] = "opzjjdrjlogfvx";
	sort<char>(arr);
	print<char>(arr);

}