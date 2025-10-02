#include "CustomStack.h"


void StaticStack::push(const std::string& thingToAddToStack)
{
	indexOfCurrentTopOfStack++;
	stringStack[indexOfCurrentTopOfStack] = thingToAddToStack;
}

std::string StaticStack::top()
{
	return stringStack[indexOfCurrentTopOfStack];
}

void StaticStack::pop()
{
	if (indexOfCurrentTopOfStack == -1) //add similar safety checks to top and push!
	{
		throw MyException("UNDERFLOW, cannot pop an EMPTY stack!\n", __LINE__, __FILE__);
		//throw std::runtime_error(""); //more generic approach 
	}

	indexOfCurrentTopOfStack--;
}

void DynamicStack::push(const std::string& thingToAddToStack)
{
	dynamicStringStack.push_back(thingToAddToStack);
}

void DynamicStack::pop()
{
	dynamicStringStack.pop_back(); 
}
