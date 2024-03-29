
#include "StringCalculator.hpp"
#include <string>
#include <vector>

StringCalculator::StringCalculator() {};

int StringCalculator::Add(std::string numbers)
{
	int output = 0;

	if (!numbers.empty())
	{
		// the general idea is to create a vector holding each number
		// from the input as distinct strings, which summed up at the
		// end -- the loop runs through the input string until a
		// delimiting character is seen, then begins the next entry

		std::vector<std::string> entries;

		entries.push_back(numbers.substr(0, 1));
		int current_entry = 0;

		for (int i = 1; i < numbers.length(); i++)
		{
			if (numbers.substr(i, 1) == "\n" || numbers.substr(i, 1) == ",") {
				current_entry++;
				i++;
				entries.push_back(numbers.substr(i, 1));
			}
			else {
				entries[current_entry] += numbers.substr(i, 1);
			}
		}

		for (const auto& entry : entries) {
			output += std::stoi(entry);
		}
	}

	return output;
}