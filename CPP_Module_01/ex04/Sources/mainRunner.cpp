#include "../Includes/fileFormatter.hpp"


namespace fileFormater {

void	mainRunner(int argc, char *argv[]) {
	if (argc != 4) {
		throw std::runtime_error("program expect 3 argument!");
	} else if (!*argv[1]) {
		throw std::runtime_error("file name cannot be emthy!");
	} else if (!*argv[2]) {
		throw std::runtime_error("string to replace cannt be emthy!");
	} else if (!*argv[3]) {
		throw std::runtime_error("string to replace with cannot be emthy!");
	}
	std::cout << YELLOW "The [" << argv[1]
		<< "] formating started!\n" RESET;
	replaceFileContent(argv[1], argv[2], argv[3]);
	std::cout << GREEN "The [" << argv[1]
		<< "] content has been formated!\n" RESET;
}

}
