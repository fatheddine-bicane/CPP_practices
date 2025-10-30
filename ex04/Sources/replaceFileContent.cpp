#include "../Includes/fileFormatter.hpp"

namespace fileFormater {

static std::string replaceLine(
	std::string& line, const std::string& s1, const std::string& s2) {
	std::string	result;
	int pos = 0;
	size_t foundPos = line.find(s1);

	while (foundPos != std::string::npos) {
		result += line.substr(pos, foundPos - pos);
		result += s2;
		pos = foundPos + s1.length();
		foundPos = line.find(s1, pos);
	}
	result += line.substr(pos);
	return result;
}

void	replaceFileContent(std::string fileName, std::string s1 ,std::string s2) {
	std::ifstream	fileToReplace(fileName);
	if (!fileToReplace.is_open()) {
		throw std::runtime_error("file doesn't exist!");
	}
	std::ofstream	formatedFile(fileName + ".replace");
	if (!formatedFile.is_open()) {
		fileToReplace.close();
		throw std::runtime_error("couldn't create a file!");
	}
	std::string	line;
	while (std::getline(fileToReplace, line, '\n')) {
		std::string modifiedLine = replaceLine(line, s1, s2);
		formatedFile << modifiedLine << "\n";
	}
	fileToReplace.close();
	formatedFile.close();
}

}
