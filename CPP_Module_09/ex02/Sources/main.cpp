#include "../Includes/PmergeMe.hpp"
#include <exception>
#include <iostream>

int	main(int argc, char** argv) {
	try {
		PmergeMe	p;
		p.applyAlgorithm(argc, argv);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
