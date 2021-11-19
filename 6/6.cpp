#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


void input(vector <string>& str, int n) {
	string string;
	for (int i = 0; i < n; i++) {
		cout << "Input string: ";
		cin >> string;
		str.push_back(string); //+1
	}
}
void reverse(vector <string>& str){
	for (int i = 0; i < str.size(); i++) {
		reverse(str[i].begin(), str[i].end());
	}
}

void sort(vector <string>& str){
	sort(str.begin(), str.end());
	
}

void output(vector <string>& str) {
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << endl;
	}
}


int main()
{
	vector <string> str;
	int n;
	cout << "Number of strings?: ";
	cin >> n;
	input(str,n);
	reverse(str);
	sort(str);
	output(str);

}