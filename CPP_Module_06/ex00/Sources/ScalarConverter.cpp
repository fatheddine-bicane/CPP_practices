#include "../Includes/ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>


// INFO: pseudo literal
bool	ScalarConverter::isPseudoLiteral(const std::string& literal) {
	return (literal == "-inff" || literal == "+inff" || literal == "nanf"
			|| literal == "-inf" || literal == "+inf" || literal == "nan");
}

void	ScalarConverter::handlePseudoLiteral(const std::string& literal){
	std::cout << "char: impossible\n"
			  << "int: impossible\n";

	if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
		std::cout << "float: " << literal << '\n'
				  << "double: " << literal.substr(0, literal.length()-1) << '\n';
	} else {
		std::cout << "float: " << literal + "f\n"
				  << "double: " << literal << '\n';
	}
}


// INFO: characters literal
bool	ScalarConverter::isCharacterLiteral(const std::string& literal) {
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

void	ScalarConverter::handleCharacterLiteral(const std::string& literal) {
	char c = static_cast<char>(literal[0]);
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	std::cout << "char: " << c
			  << "\nint: " << i
			  << "\nfloat: " << f
			  << "\ndouble: " << d << '\n';
}


// INFO: integer literal
bool	ScalarConverter::isIntegerLiteral(const std::string& literal) {
	int i = 0;
	int end = literal.length();
	if (literal[0] == '+' || literal[0] == '-') i++;
	while (i < end && isdigit(literal[i])) i++;
	return (i == end);
}

void	ScalarConverter::handleIntegerLiteral(const std::string& literal) {
	char* end;
	long i = std::strtol(literal.c_str(), &end, 10);
	if (*end != '\0' || i < INT_MIN || i > INT_MAX) {
		throw std::runtime_error("The integer value exceeds the limits");
	}
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	if (i < 0 || i > 127) {
		std::cout << "char: impossible";
	} else if (!std::isprint(c)) {
		std::cout << "char: Non displayable";
	} else {
		std::cout << "char: '" << c << "'";
	}
	std::cout << "\nint: " << i
			  << "\nfloat: " << f << "f"
			  << "\ndouble: " << d << '\n';
}


// INFO: float literal
bool	ScalarConverter::isFloatLiteral(const std::string& literal) {
	int i = 0;
	int len = literal.length();
	bool hasDecimal = false;
	if (len < 4) return false;
	if (literal[len - 1] != 'f') return false;
	if (literal[0] == '+' || literal[0] == '-') i++;
	while (i < len - 1) {
		if (literal[i] == '.') {
			if (hasDecimal) return false;
			hasDecimal = true;
		} else if (!std::isdigit(literal[i])) {
			return false;
		}
		i++;
	}
	return hasDecimal;
}

void	ScalarConverter::handleFloatLiteral(const std::string& literal) {
	char* end;
	double tmp = std::strtod(literal.c_str(), &end);
	if (*end != 'f') {
		throw std::runtime_error("Invalid float literal");
	}
	float f = static_cast<float>(tmp);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	if (f < 0 || f > 127) {
		std::cout << "char: impossible";
	} else if (!std::isprint(c)) {
		std::cout << "char: Non displayable";
	} else {
		std::cout << "char: '" << c << "'";
	}
	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX)) {
		std::cout << "\nint: impossible";
	} else {
		std::cout << "\nint: " << i;
	}
	std::cout << "\nfloat: " << f << "f"
			  << "\ndouble: " << d << '\n';
}


// INFO: double literal
bool	ScalarConverter::isDoubleLiteral(const std::string& literal) {
	int i = 0;
	int len = literal.length();
	bool hasDecimal = false;
	if (len < 2) return false;
	if (literal[0] == '+' || literal[0] == '-') i++;
	while (i < len) {
		if (literal[i] == '.') {
			if (hasDecimal) return false;
			hasDecimal = true;
		} else if (!std::isdigit(literal[i])) {
			return false;
		}
		i++;
	}
	return hasDecimal;
}

void	ScalarConverter::handleDoubleLiteral(const std::string& literal) {
	char* end;
	double d = std::strtod(literal.c_str(), &end);
	if (*end != '\0') {
		throw std::runtime_error("Invalid double literal");
	}
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	if (d < 0 || d > 127) {
		std::cout << "char: impossible";
	} else if (!std::isprint(c)) {
		std::cout << "char: Non displayable";
	} else {
		std::cout << "char: '" << c << "'";
	}
	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX)) {
		std::cout << "\nint: impossible";
	} else {
		std::cout << "\nint: " << i;
	}
	std::cout << "\nfloat: " << f << "f"
			  << "\ndouble: " << d << '\n';
}


void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cerr << "Empty input detected!\n";
	} else if (isPseudoLiteral(literal)) {
		handlePseudoLiteral(literal);
	} else if (isCharacterLiteral(literal)) {
		handleCharacterLiteral(literal);
	} else if (isIntegerLiteral(literal)) {
		handleIntegerLiteral(literal);
	} else if (isFloatLiteral(literal)) {
		handleFloatLiteral(literal);
	} else if (isDoubleLiteral(literal)) {
		handleDoubleLiteral(literal);
	} else {
		std::cerr << "Invalid literal\n";
	}
}
