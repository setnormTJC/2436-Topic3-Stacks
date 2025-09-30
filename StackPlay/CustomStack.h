#pragma once
#include <string>
#include <iostream>
#include <vector>


class StackADT //"Abstract data type" (SOME might name this class "IStack" -> as in "Interface for a stack")
{
	//fill me in (with some pure virtual functions)
};

class CustomStack : public StackADT //consider renaming CustomStack to CStyleStack
{
private: 
	static constexpr int stackSize = 5; 

	std::string stringStack[stackSize]; //C-style array (a pointer in disguise)
	int indexOfCurrentTopOfStack = -1; 

public: 
	CustomStack() = default; 
	
	/*Also called "peek"*/
	std::string top(); 

	/*pop removes the top element on the stack (if it exists) */
	void pop(); 

	/*push puts something onto the stack of elements*/
	void push(const std::string& thingToAddToStack);

};

class VectorStack : public StackADT
{
private: 
	std::vector<std::string> dynamicStringStack; 
public: 
	//fill me in with "concrete" methods that override the parent class's pure virtual functions  
};


