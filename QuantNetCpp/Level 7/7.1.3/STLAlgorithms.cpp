/*
	C++ code for HW7, Exercise 3
*/

/*

STL already contains many algorithms that work with containers. 
Use the count_if algorithm to count the number of elements smaller than a certain number.
The count_if function accepts a functor. 
Thus pass it a global function that checks the double input is smaller than a certain value.

Replace the global checking function, by a function object.
This is a class that overload the round bracket operator that in this case has the same signature and functionality as the global function you created previously.
Only in this case the value to check for should not be a ‘literal’ value, but taken from a data member that was set in the constructor of the function object.

*/