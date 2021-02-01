
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

TEST_CASE("Single number returns its value") {

	StringCalculator s;

	int testnumber = 145;
	std::string num = std::to_string(testnumber);

	REQUIRE(s.Add(num) == testnumber);
}

TEST_CASE("Two comma-delimited numbers return sum") {

	StringCalculator s;

	int testnumber1 = 15;
	int testnumber2 = 27;

	std::string input = std::to_string(testnumber1);
	input += ",";
	input += std::to_string(testnumber2);

	REQUIRE(s.Add(input) == testnumber1 + testnumber2);
}

TEST_CASE("Two newline-delimited numbers return sum") {
	
	StringCalculator s;

	int testnumber1 = 314;
	int testnumber2 = 372;

	std::string input = std::to_string(testnumber1);
	input += "\n";
	input += std::to_string(testnumber2);

	REQUIRE(s.Add(input) == testnumber1 + testnumber2);
}

TEST_CASE("Three delimited numbers return sum") {

	StringCalculator s;

	int testnumber1 = 314;
	int testnumber2 = 372;
	int testnumber3 = 336;

	std::string input = std::to_string(testnumber1);
	input += "\n";
	input += std::to_string(testnumber2);
	input += "\n";
	input += std::to_string(testnumber3);

	REQUIRE(s.Add(input) == testnumber1 + testnumber2 + testnumber3);

	input.clear();
	input = std::to_string(testnumber1);
	input += ",";
	input += std::to_string(testnumber2);
	input += ",";
	input += std::to_string(testnumber3);

	REQUIRE(s.Add(input) == testnumber1 + testnumber2 + testnumber3);

	input.clear();
	input = std::to_string(testnumber1);
	input += "\n";
	input += std::to_string(testnumber2);
	input += ",";
	input += std::to_string(testnumber3);

	REQUIRE(s.Add(input) == testnumber1 + testnumber2 + testnumber3);

	input.clear();
	input = std::to_string(testnumber1);
	input += ",";
	input += std::to_string(testnumber2);
	input += "\n";
	input += std::to_string(testnumber3);

	REQUIRE(s.Add(input) == testnumber1 + testnumber2 + testnumber3);
}

TEST_CASE("Negative Numbers Throw an Exception") {

	StringCalculator s;

	int testnumber1 = 15;
	int testnumber2 = -22;
	int testnumber3 = 107;

	// since negatives should always lead to an exception, need to test
	// each possible case w/ a negative input; will start w/ a single
	// negative value, then w/ two values, and finally w/ three

	std::string input = std::to_string(testnumber2);

	REQUIRE_THROWS_AS(s.Add(input), std::domain_error);

	input.clear();
	input = std::to_string(testnumber1);
	input += ",";
	input += std::to_string(testnumber2);

	REQUIRE_THROWS_AS(s.Add(input), std::domain_error);

	input.clear();
	input = std::to_string(testnumber2);
	input += ",";
	input += std::to_string(testnumber1);

	REQUIRE_THROWS_AS(s.Add(input), std::domain_error);

	input.clear();
	input = std::to_string(testnumber2);
	input += ",";
	input += std::to_string(testnumber1);
	input += ",";
	input += std::to_string(testnumber3);

	REQUIRE_THROWS_AS(s.Add(input), std::domain_error);

	input.clear();
	input = std::to_string(testnumber1);
	input += ",";
	input += std::to_string(testnumber2);
	input += ",";
	input += std::to_string(testnumber3);

	REQUIRE_THROWS_AS(s.Add(input), std::domain_error);

	input.clear();
	input = std::to_string(testnumber1);
	input += ",";
	input += std::to_string(testnumber1);
	input += ",";
	input += std::to_string(testnumber2);

	REQUIRE_THROWS_AS(s.Add(input), std::domain_error);
}

TEST_CASE("Numbers >1000 are ignored") {

	StringCalculator s;

	int testnumber1 = 1314;
	int testnumber2 = 372;
	int testnumber3 = 1336;

	std::string input = std::to_string(testnumber1);

	REQUIRE(s.Add(input) == 0);

	input += ",";
	input += std::to_string(testnumber2);
	input += ",";
	input += std::to_string(testnumber3);

	REQUIRE(s.Add(input) == testnumber2);
}