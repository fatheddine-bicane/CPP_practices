#include "../Includes/iter.hpp"
#include <iostream>
#include <string>


void	modifyInteger(int &x) {
	x *= -1;
	std::cout << x << '\n';
}

void	printInteger(const int &x) {
	std::cout << x << '\n';
}

void	modifyString(std::string& str) {
	str += "_modified";
	std::cout << str << '\n';
}

void	printString(const std::string& str) {
	std::cout << str << '\n';
}

int main() {
    int			intArray[3] = {1, 2, 3};
	std::string	strArray[3] = {"str1", "str2", "str3"};

	std::cout << "=======================================================" << std::endl;
	std::cout << "TEST 1: iterating over 'intArray' witouth modifying it" << std::endl;
	std::cout << "=======================================================" << std::endl;
	iter(&intArray, 3, printInteger);
	std::cout << "=======================================================" << std::endl;

	std::cout << std::endl;

	std::cout << "=======================================================" << std::endl;
	std::cout << "TEST 2: iterating over 'intArray' and modify it" << std::endl;
	std::cout << "=======================================================" << std::endl;
	iter(&intArray, 3, modifyInteger);
	std::cout << "=======================================================" << std::endl;

	std::cout << std::endl;

	std::cout << "=======================================================" << std::endl;
	std::cout << "TEST 3: iterating over 'strArray' witouth modifying it" << std::endl;
	std::cout << "=======================================================" << std::endl;
	iter(&strArray, 3, printString);
	std::cout << "=======================================================" << std::endl;

	std::cout << std::endl;

	std::cout << "=======================================================" << std::endl;
	std::cout << "TEST 4: iterating over 'strArray' and modify it" << std::endl;
	std::cout << "=======================================================" << std::endl;
	iter(&strArray, 3, modifyString);
	std::cout << "=======================================================" << std::endl;
}
