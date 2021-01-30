
#include "StringCalculator.hpp"
#include <string>

StringCalculator::StringCalculator() {};

int StringCalculator::Add(std::string numbers)
{
	int output = 0;

	std::string delim = ",";

	if (!numbers.empty())
	{
		size_t delimeter_position = numbers.find(delim);

		if (delimeter_position != std::string::npos)
		{
			output += std::stoi(numbers.substr(0, delimeter_position));
			output += std::stoi(numbers.substr(delimeter_position + 1));
		}
		else if (numbers.find("\n") != std::string::npos)
		{
			delimeter_position = numbers.find("\n");

			output += std::stoi(numbers.substr(0, delimeter_position));
			output += std::stoi(numbers.substr(delimeter_position + 1));
		}
		else
		{
			output = std::stoi(numbers);
		}
	}

	return output;
}