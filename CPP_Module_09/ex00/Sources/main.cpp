#include "../Includes/BitcoinExchange.hpp"

int	main(int argc, char** argv) {
	BitcoinExchange btc;

	// read data base
	btc.readDataBase();

	// parse input file
	(void)argc;
	btc.evaluateInputFile(argv[1]);



	// find rlated prices and print them
}
