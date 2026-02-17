#include "../Includes/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "The program expect one strigng literal!\n";
		return 1;
	}
	try {
		ScalarConverter::convert(argv[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
