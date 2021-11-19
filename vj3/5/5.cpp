#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iterator>

using namespace std;
using std::string;

size_t count_substr(const string& s1, const string& s2)
{
	int count = 0;
	int x = s1.find(s2, 0);
	while (x != string::npos) //kraj stringa
	{
		count++;
		x = s1.find(s2, x + 1);
	}
	return count;

}
int main()
{
	string str{ "Ovo je je je je je string  " };
	string substr{ "je" };
	int n = count_substr(str, substr);
	cout << "Broj ponavljanja substringa u stringu je:" << n << endl;

}