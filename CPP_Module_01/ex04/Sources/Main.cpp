#include "../Includes/fileFormatter.hpp"


int main(int argc, char *argv[]) {
	try {
		fileFormater::mainRunner(argc, argv);
	} catch (std::exception& error) {
		std::cerr << RED "An error occurred: "
			<< error.what() << RESET << std::endl;
		std::exit(1);
	}
}
