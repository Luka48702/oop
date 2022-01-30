#include <fstream>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;

int main(const string& fileName, vector<int>& numbers)
{

	try {
		ifstream file;

		file.open("numbers.txt");
		if (!file.is_open()) {
			throw exception();
		}

		istream_iterator<int>it(file);
		istream_iterator<int>eof;
		copy(it, eof, back_inserter(numbers));
	}

	catch (string errorname) {
		cout << errorname << endl;
		return 1;
	}

	vector<int> vector;

	int counter = count_if(vector.begin(), vector.end(), [](int i) { return i > 500; });
	cout << "Number of numbers greater than 500: " << counter << endl;

	int minElement = *min(vector.begin(), vector.end());
	cout << "Min element: " << minElement << endl;

	int maxElement = *max_element(vector.begin(), vector.end());
	cout << "Max element: " << maxElement << endl;

	vector.erase(remove_if(vector.begin(), vector.end(), [](int i) { return i < 300; }), vector.end());

	sort(vector.begin(), vector.end(), greater<int>());

	for (auto num : vector) {
		cout << num << endl;
	}
}
