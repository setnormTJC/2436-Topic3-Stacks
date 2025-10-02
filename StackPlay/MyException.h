#pragma once
#include <string>
class MyException/* : public std::exception*/
{
private:
	std::string errorMessage{};
	int lineNumber{};
	const char* filename{};
public:
	MyException(const std::string& errorMessage, const int lineNumber, const char* filename)
		:errorMessage(errorMessage), lineNumber(lineNumber), filename(filename)
	{
	}

	std::string whatWentWrong() const;
};

