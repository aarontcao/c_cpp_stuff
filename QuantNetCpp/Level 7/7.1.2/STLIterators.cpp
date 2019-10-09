/*
	C++ code for HW7, Exercise 2
*/

#include <list>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

// Template function Sum() accepts template arg T, returns double
template<typename T>
double Sum(const T& t) {
	// iterator
	typename T::const_iterator i;
	double sum = 0.0;

	for (i = t.begin(); i != t.end(); i++) {
		sum += *i;
	}
	return sum;
}

// Calculate the sum of all values between two passed-in iterators
template <typename T>
double Sum(const typename T::const_iterator& start, const typename T::const_iterator& end) {
	typename T::const_iterator i;
	double sum = 0.0;

	for (i = start; i != end; i++) {
		sum += *i;
	}
	return sum;
}

int main() {
	//  call Sum() for the different conntainers from previous exercise

	// List of doubles
	list<double> ls;
	for (int i = 0; i < 10; i++)
	{
		ls.push_back(i);
		ls.push_front(-i);
	}

	cout << "Sum of list elements : " << Sum(ls) << endl;

	// Vector of doubles
	vector<double> vec(3);
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}

	cout << "Vector contents: " << Sum(vec);

	// Map that maps strings to doubles
	map<string, double> myMap;

	string str[4] = { "0", "1", "2", "3" };

	for (int i = 0; i < 4; i++)
	{
		myMap[str[i]] = i * 10.0;
	}

	cout << "Map contents: " << Sum(myMap);

	return 0;
}