#include <iostream>
#include <string>
#include <cctype>

static void	oneArgument(void) {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

static std::string	capitalize(std::string arg) {
	std::string	result;

	for (int i = 0; arg[i]; i++) {
		result.push_back(std::toupper(arg[i]));
	}
	result.push_back('\0');
	return result;
}

static void	multipleArguments(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		std::cout << capitalize(argv[i]);
	}
	std::cout << std::endl;
}

int	main(int argc, char *argv[]) {
	if (argc == 1) {
		oneArgument();
	} else {
		multipleArguments(argc, argv);
	}
}
