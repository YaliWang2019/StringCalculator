
#include "StringCalculator.hpp"
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

bool DelimSetContains(std::unordered_set<std::string> delimiters, const std::string s)
{
	auto set_check = delimiters.find(s);
	return set_check != delimiters.end();
}

StringCalculator::StringCalculator() {};

int StringCalculator::Add(std::string numbers)
{
	int output = 0;

	if (!numbers.empty())
	{
		// the general idea is to create a vector holding each number
		// from the input as distinct strings, which is summed up at the
		// end -- the loop runs through the input string until a
		// delimiting character is seen, then begins the next entry

		std::vector<std::string> entries;
		std::unordered_set<std::string> delims;

		delims.insert("\n");
		delims.insert(",");

		int curr_pos = 0;

		if (!isdigit(numbers[0]) && numbers[0] != '-' && numbers[0] != '[')
		{
			delims.insert(std::string(1, numbers[0]));
			numbers = numbers.substr(1);
		}
		else if (numbers[0] == '[')
		{
			curr_pos++;
			std::string cust_delim;
			while (numbers[curr_pos] != ']')
			{
				cust_delim += numbers[curr_pos];
				curr_pos++;

				if (curr_pos == numbers.length())
				{
					throw std::invalid_argument("Custom delimiter defintion incomplete.");
				}
			}

			delims.insert(cust_delim);
			curr_pos++;
		}

		entries.push_back(numbers.substr(curr_pos, 1));
		int current_entry = 0;
		curr_pos++;

		for (int i = curr_pos; i < numbers.length(); i++)
		{
			if (!isdigit(numbers[i]))
			{
				// NOTE : this method has the potential to 'skip' an entered
				//        negative number thinking the '-' was the beginning of
				//        a custom delimiter; en exception will still be raised,
				//        just not the domain exception regarding negatives

				std::string possible_delimiter(1, numbers[i]);
				while (!DelimSetContains(delims, possible_delimiter))
				{
					i++;
					if (i == numbers.length()) throw std::invalid_argument("Invalid delimiter led to reading end of input");
					
					possible_delimiter += numbers[i];
				}
				
				current_entry++;
				i++;
				if (i < numbers.length()) entries.push_back(numbers.substr(i, 1));
			}
			else {
				entries[current_entry] += numbers[i];
			}
		}

		for (const auto& entry : entries) {
			
			int new_value = std::stoi(entry);
			if (new_value < 0) throw std::domain_error("Negative input not allowed. Improper value : " + std::to_string(new_value));
			if (new_value > 1000) continue;
			output += new_value;
		}
	}

	return output;
}