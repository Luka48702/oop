// 1i2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <vector>
#include "Header.hpp"

vector<int> input(vector<int>& arr, int n){
	int v; 
	int n2 = (n * 2);
	for (auto i = 0; i < n2; ++i)
	{
		cout << "enter the element" << endl;
		cin >> v;
		arr.push_back(v);
	}
	return arr;
}
vector<int> input2(vector<int>& arr, int x, int y)
{
	int v;
	cout << "enter the element" << endl;
	cin >> v;
	while (x < v && v < y)
	{
		arr.push_back(v);
		cout << "enter the element" << endl;
		cin >> v;
	}
	return arr;
}
void print(vector<int>& arr) {
	for (int j = 0;;) {

		for (auto i = arr.begin(); i != arr.end(); ++i)
		{
			cout << arr.at(j) << endl;
			j++;
		}
		cout << endl;
		break;
	}
}

vector<int> input3(vector<int>& arr1, vector<int>& arr2) 
{
		vector <int> v;
		for (int q = 0;;) {
			for (auto i = arr1.begin(); i != arr1.end(); ++i) {
				int a = 0;
				for (auto j = arr2.begin(); j != arr2.end(); ++j) {

					if (arr1.at(q) != arr2.at(a)) {
						v.push_back(arr1.at(q));
						break;
					}
					a++;
				}
				q++;
			}
			break;
		}
		return v;
}

	int main() {
		int n;
		cout << "Size: " << endl;
		cin >> n;
		vector<int> vec;
		input(vec, n);
		int x, y;
		cout << "enter the lower limit" << endl;
		cin >> x;
		cout << "enter the upper limit" << endl;
		cin >> y;
		vector <int> vec_tor;
		input2(vec_tor, x, y);
		cout << " " << endl;
		vector <int> v1;
		vector <int> v2;
		input(v1, 5);
		input(v2, 5);
		vector <int> v3;
		v3 = input3(v1, v2);
		print(v3);
	}