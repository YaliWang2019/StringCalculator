
#include "Catch.hpp"
#include "StringCalculator.hpp"

#include <string>

// 1. An empty string returns zero
// 2. A single number returns the value
// 3. Two numbers, comma delimited, returns the sum
// 4. Two numbers, newline delimited, returns the sum
// 5. Three numbers, delimited either way, returns the sum
// 6. Negative numbers throw an exception
// 7. Numbers greater than 1000 are ignored
// 8. A single char delimiter can be defined on the first line(e.g. //# for a ‘#’ as the delimiter)
// 9. A multi char delimiter can be defined on the first line(e.g. //[###] for ‘###’ as the delimiter)
// 10. Many single or multi - char delimiters can be defined(each wrapped in square brackets)

TEST_CASE( "Empty string returns 0") {

	StringCalculator s;
	std::string num = "";

	REQUIRE(s.Add(num) == 0);
}