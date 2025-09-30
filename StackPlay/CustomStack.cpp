#include "CustomStack.h"


void CustomStack::push(const std::string& thingToAddToStack)
{
	indexOfCurrentTopOfStack++;
	stringStack[indexOfCurrentTopOfStack] = thingToAddToStack;
}

std::string CustomStack::top()
{
	return stringStack[indexOfCurrentTopOfStack];
}

void CustomStack::pop()
{
	if (indexOfCurrentTopOfStack == -1) //add similar safety checks to top and push!
	{
		throw std::runtime_error("Cannot pop an EMPTY stack!\n");
	}

	indexOfCurrentTopOfStack--;
}