//Programmer: Derek Shunia/
/*************************/
//Operating Systems HW 1--/
/*************************/
//Due: Oct 04, 2015------//

/*I have neither given nor recieved unauthorized
//aid in completing this work, nor have I presented
//someone else's work as my own.*/

//headers
#include <thread>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

//input: size, vector
//output: vector of Fibonacci values
vector<int> fib(int numberOfIterations, vector<int> &sequence)
{
	//initalize vector of integers to store sequence in
	sequence.resize(numberOfIterations);

	//set initial conditions after checking for clean input
	if (numberOfIterations > 0) sequence[0] = 0;
	else cout << "Must sequence at least one number!\n";
	if (numberOfIterations > 1) sequence[1] = 1;

	//iterate through vector and generate fib sequence
	if (numberOfIterations > 2)
	{
		for (int i = 2; i < numberOfIterations; i++)
		{
			sequence[i] = sequence[i - 1] + sequence[i - 2];
		}
	}

	return sequence;
}

//input: string
//output: is the string is an integer?
bool isNumber(string s)
{
	bool n = true;
	for(string::const_iterator k = s.begin(); k != s.end(); ++k)
		n = n && isdigit(*k);
	return n;
}

//input: nothing
//output: integer for size of Fibonacci sequence
int getUserInput()
{
	string cinput;
	cout << "Enter the size of Fibonacci sequence: ";
	do
	{
		cin >> cinput;
		if (!isNumber(cinput)) cout << "Input is not a number. Please try again: ";
	} while (!isNumber(cinput));

	return atoi(cinput.c_str());
}

//input: vector of values
//output: printed values to console screen
void printVector(vector<int> v)
{
	cout << "Fibonacci sequence: ";

	for (vector<int>::const_iterator k = v.begin(); k != v.end(); ++k)
		cout << *k << " ";
	cout << endl;
}

int main()
{
	vector<int> sequence;
	
	int numberOfIterations = 0;

	//get input from user and make sure it is clean
	numberOfIterations = getUserInput();

	//start child thread
	auto thread = async(fib, numberOfIterations, sequence);
	//return from child thread with return values
	sequence = thread.get();

	//print the sequence onto the console window
	printVector(sequence);

	system("pause");
	return 0;
}