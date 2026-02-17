#pragma once

#include <string>

class ScalarConverter {
private:
	ScalarConverter();
	// INFO: pseudo literal
	static bool	isPseudoLiteral(const std::string& literal);
	static void	handlePseudoLiteral(const std::string& literal);
	// INFO: characters literal
	static bool	isCharacterLiteral(const std::string& literal);
	static void	handleCharacterLiteral(const std::string& literal);
	// INFO: integer literal
	static bool	isIntegerLiteral(const std::string& literal);
	static void	handleIntegerLiteral(const std::string& literal);
	// INFO: float literal
	static bool	isFloatLiteral(const std::string& literal);
	static void	handleFloatLiteral(const std::string& literal);
	// INFO: double literal
	static bool	isDoubleLiteral(const std::string& literal);
	static void	handleDoubleLiteral(const std::string& literal);

public:
	static void convert(const std::string& literal);
};
