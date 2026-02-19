#include "../Includes/Array.hpp"
#include <iostream>
#include <ostream>
#include <sstream>

int main() {
	std::cout << "=======================================================" << std::endl;
	std::cout << "TEST1: array of strings" << std::endl;
	std::cout << "=======================================================" << std::endl;
	Array<std::string> strs(5);
	std::cout << "array size: " << strs.size() << std::endl;

	std::cout << "array filling and indexing:"<< std::endl;
	for (unsigned int i = 0; i < strs.size(); i++) {
		std::stringstream ss;
		ss << "str" << i + 1;
		strs[i] = ss.str();
		std::cout << strs[i] << std::endl;
	}

	std::cout << "trying to index an out-of-range element:" << std::endl;
	try {
		strs[54];
	} catch (std::exception& e) {
		std::cout << "An error occurred: " << e.what() << std::endl;
	}
	std::cout << "=======================================================" << std::endl;
	std::cout << std::endl;
	

	std::cout << "=======================================================" << std::endl;
	std::cout << "TEST2: array of integers" << std::endl;
	std::cout << "=======================================================" << std::endl;
	Array<int> ints(10);
	std::cout << "array size: " << strs.size() << std::endl;

	std::cout << "array filling and indexing: " << std::endl;
	for (unsigned int i = 0; i < ints.size(); i++) {
		ints[i] = i + 1;
		std::cout << ints[i] << std::endl;
	}

	std::cout << "trying to index an out-of-range element: " << std::endl;
	try {
		ints[ints.size()];
	} catch (std::exception& e) {
		std::cout << "An error occurred: " << e.what() << std::endl;
	}
	std::cout << "=======================================================" << std::endl;
}
