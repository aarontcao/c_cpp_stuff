/*
	C++ code for HW7, Exercise 1
*/

#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// List of doubles
	list<double> ls;
	for (int i = 0; i < 10; i++)
	{
		ls.push_back(i);
		ls.push_front(-i);
	}

	cout << "First element: " << ls.front() << endl;
	cout << "Last element: " << ls.back() << endl;

	// Vector of doubles
	vector<double> vec(3);
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}

	cout << "Vector contents: ";
	for (size_t i = 0; i < vec.size()-1; i++)
	{
		cout << vec[i] << ",";
	}

	cout << vec[vec.size()-1] << endl;

	// Map that maps strings to doubles
	map<string, double> myMap;

	string str[4] = { "0", "1", "2", "3" };

	for (int i = 0; i < 4; i++)
	{
		myMap[str[i]] = i * 10.0;
	}

	cout << "Map contents: ";
	for (size_t i = 0; i < myMap.size() - 1; i++)
	{
		cout << myMap[str[i]] << ",";
	}
	cout << myMap[str[myMap.size() - 1]];


	return 0;
}