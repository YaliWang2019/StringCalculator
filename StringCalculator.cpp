
#include "StringCalculator.hpp"
#include <string>

StringCalculator::StringCalculator() {};

int StringCalculator::Add(std::string numbers)
{
	int output = 0;

	if (!numbers.empty())
	{
		output = std::stoi(numbers);
	}

	return output;
}