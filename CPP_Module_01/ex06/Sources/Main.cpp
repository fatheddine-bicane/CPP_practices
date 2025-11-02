#include "../Includes/harlComplaining.hpp"


void	mainRunner(int argc, char* argv[]) {
	if (argc != 2) {
		throw std::runtime_error("program takes one arguemnt.\n");
	}
	harlFilter::Harl harl;
	harl.complain(argv[1]);
}

int main(int argc, char* argv[]) {
	try {
		mainRunner(argc, argv);
	} catch (std::exception& error) {
		std::cerr << RED "An error occurred: "
			<< error.what() << RESET;
		return 1;
	}
}
