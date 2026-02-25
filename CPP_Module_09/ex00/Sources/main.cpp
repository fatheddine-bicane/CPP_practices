#include "../Includes/BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char** argv) {
	BitcoinExchange btc;
	if (argc != 2) {
		std::cerr << "Error: program takes an input file!\n";
		return 1;
	}

	btc.readDataBase();

	// parse input file
	try {
		btc.evaluateInputFile(argv[1]);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
