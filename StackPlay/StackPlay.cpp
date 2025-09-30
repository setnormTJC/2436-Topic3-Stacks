// StackPlay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CustomStack.h"

int main()
{
	//const std::string anExpression = "((5 + 3)/2)";
	//checking that the above expression is "balanced" is a classic application 
	//of a stack data structure

	try
	{
		CustomStack myStackyOf5Strings; 

		myStackyOf5Strings.push("Bob");

		myStackyOf5Strings.push("Alice");

		myStackyOf5Strings.push("Carol");

		myStackyOf5Strings.pop(); 

		myStackyOf5Strings.push("Darth");

		myStackyOf5Strings.pop(); 

		std::cout << "Top contents after pushing a few and popping a couple:\n";
		std::cout << myStackyOf5Strings.top() << "\n"; //SHOULD be "Alice"


		myStackyOf5Strings.pop(); 
		myStackyOf5Strings.pop();
		myStackyOf5Strings.pop(); //throws exception!
		//myStackyOf5Strings.pop();
	} 

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

