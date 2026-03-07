#include "../Includes/RPN.hpp"
#include <iostream>

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: program expect one expression!\n";
		return 1;
	}

	RPN	rpn;
	try {
		rpn.evaluateExpression(argv[1]);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
