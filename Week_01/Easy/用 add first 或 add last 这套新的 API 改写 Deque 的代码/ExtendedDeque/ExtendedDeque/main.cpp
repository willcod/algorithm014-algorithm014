// ExtendedDeque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "ExtendDeque.h"
#include "main.h"

using std::string;
using std::endl;
using std::cout;


template< typename T>
void printDeque(ExtendDeque<T>& deque)
{
	for (T e : deque)
		cout << e;
	
}

int main()
{
	cout << "AddFirstMethodTest" << endl;
	AddFirstMethodTest();

	cout << endl;

	cout << "AddLastMethodTest" << endl;
	AddLastMethodTest();
}

void AddFirstMethodTest()
{
	ExtendDeque<string> deque;
	deque.add_first("a");
	deque.add_first("b");
	deque.add_first("c");
	printDeque(deque);
	auto str = deque.front();
	cout << endl << str << endl;
	printDeque(deque);
	cout << endl;

	while (deque.size())
	{
		cout << deque.front() << endl;
		deque.pop_front();
	}
	printDeque(deque);
}

void AddLastMethodTest()
{
	ExtendDeque<string> deque;
	deque.add_last("a");
	deque.add_last("b");
	deque.add_last("c");
	printDeque(deque);
	auto str = deque.front();
	cout << endl << str << endl;
	printDeque(deque);
	cout << endl;

	while (deque.size())
	{
		cout << deque.front() << endl;
		deque.pop_front();
	}
	printDeque(deque);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
