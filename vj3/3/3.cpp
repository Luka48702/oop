#include <iostream>
using namespace std;
#include "Header.hpp"
#include <vector>
#include <algorithm>
#include <iterator>


int suma(vector<int>& v)
{
	int count = 0;
	for (int j = 0;;) {
		for (auto i = v.begin(); i != v.end(); ++i) {
			count = count + v.at(j);
			j++;
		}
		break;
	}
	return count;
}


	int main() {

		vector <int> v;
		input(v, 2);
		sort(v.begin(), v.end());
		int s = suma(v);
		cout << "" << endl;
		v.insert(v.begin(), 0);
		v.push_back(s);
		print(v);
	}