#pragma once

#include <cstddef>
#include <stack>
#include <string>


class RPN {
private:
	std::stack<int>			_expression;
	std::string::iterator	_current;
	std::string				_input;
	size_t					_stack_count;
	char					_operation;


	bool	isOperation();
	void	consumeDigit();
	void	consumeOperation();
	void	evaluateTopTwoElements();

public:

	// INFO: orthodox canonical
	RPN();
	RPN(const RPN& other);
	RPN&	operator=(const RPN& other);
	~RPN();

	void	evaluateExpression(const std::string& input);
};
