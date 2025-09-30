/*
* This program still needs work as of Sept. 30 around 2 pm
*/

#include <functional>
#include <iostream>


template<typename function, int stackSize> 
class FunctionCallStack
{
private:
	function stackOhFunctions[stackSize];
	int indexOfCurrentTopOfStack = 0; 
public:
	void push(const function& function)
	{
		if (indexOfCurrentTopOfStack > stackSize - 1)
		{
			throw std::runtime_error("stack overflow!");
		}

		//"implied else": 
		stackOhFunctions[indexOfCurrentTopOfStack] = function; 

		indexOfCurrentTopOfStack++; 
	}
	/*One goal of this function - print the return value
	* of function that is currently on top of stack 
	*/
	void pop()
	{
		if (indexOfCurrentTopOfStack < 0)
		{
			throw std::runtime_error("Stack UNDERflow\n");
		}

		std::cout << "Function on top of stack returned: ";
		std::cout << stackOhFunctions[function()] << "\n";

		indexOfCurrentTopOfStack--; 
	}
};

int main()
{
	constexpr int stackSize = 5; 

	FunctionCallStack<std::function<int()>, stackSize> theCallStack;
	/*New thing here! std::function<int()>
	* This means the function returns an int and takes 0 args
	*/

	auto myPow =
		[]()
		{

		};

	//std::cout << myPow(3, 4) << "\n";

	try
	{

		theCallStack.push(myPow);

		theCallStack.pop();

	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}



}

