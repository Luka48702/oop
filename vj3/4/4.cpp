#include <iostream>
using namespace std;
#include "Header.hpp"
#include <vector>
#include <algorithm>
#include <iterator>



vector<int> erase(vector<int>& v)
{
	cout << "ako zelite prestat brisat pritisnite Ctrl + z" << endl;
	cout << "Izbriste element na mjestu n:" << endl;
	cout << "Unesi n: " << endl;
	int n;
	while (cin >> n) {
		v.erase(v.begin() + n);
	}
	return v;
}
int main()
{

	vector <int> v;
	input(v, 2);
	cout << "" << endl;
	erase(v);
	cout << "" << endl;
}