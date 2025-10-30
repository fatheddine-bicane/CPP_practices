#include <string>
#include <iostream>

int main() {
	std::string		brain = "HI THIS IS BRAIN";
	std::string		*stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << &brain << "\n"
		<< &stringPTR << "\n"
		<< &stringREF << "\n";

	std::cout << brain << "\n"
		<< *stringPTR << "\n"
		<< stringREF << "\n";

}
