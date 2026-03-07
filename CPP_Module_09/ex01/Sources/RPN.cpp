#include "../Includes/RPN.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

// INFO: orthodox canonical
// ------------------------------------------------------------------------
RPN::RPN() {}

RPN::RPN(const RPN& other) {
	(void) other;
}

RPN& RPN::operator=(const RPN& other) {
	(void) other;
	return *this;
}

RPN::~RPN() {}
// ------------------------------------------------------------------------


// INFO: helper methods
// ------------------------------------------------------------------------

bool	RPN::isOperation() {
	std::string	operations = "+-/*";
	char	operation = *this->_current;
	size_t		is_operation = operations.find(operation);

	if (is_operation == std::string::npos) {
		return false;
	}
	return true;
}

void	RPN::consumeDigit() {
	int value = *this->_current - 48;
	this->_expression.push(value);

	this->_current++;
	if (*this->_current != ' ') {
		// informe the user that null terminator is encountered while expecting a token
		std::string token;
		if (*this->_current == '\0') {
			token = "end of input";
		} else {
			token = *this->_current;
		}

		std::stringstream ss_err;
		ss_err <<"unexpected token: '" << token
			<< "'. Expected separator token: (space)!";
		throw std::runtime_error(ss_err.str());
	}

	this->_stack_count++;
	this->_current++;
}


void	RPN::consumeOperation() {
	if (this->_stack_count < 2) {
		std::stringstream ss_err;
		ss_err << "two operands needed to perform '"
			<< *this->_current << "' operation!";
		throw std::runtime_error(ss_err.str());
	}

	this->_operation = *this->_current;

	this->_current++;
	if (this->_current == this->_input.end()) {
		return;
	} else if (*this->_current != ' ') {
		std::stringstream ss_err;
		ss_err <<"unexpected token: '" << *this->_current
			<< "'. Expected separator token: (space)!";
		throw std::runtime_error(ss_err.str());
	}

	this->_current++;
}

void	RPN::evaluateTopTwoElements() {
	int	rhs = this->_expression.top();
	this->_expression.pop();
	int	lhs = this->_expression.top();
	this->_expression.pop();
	this->_stack_count -= 2;

	switch (this->_operation) {
		case '+':
			this->_expression.push(lhs + rhs);
			break;

		case '-':
			this->_expression.push(lhs - rhs);
			break;

		case '*':
			this->_expression.push(lhs * rhs);
			break;

		case '/':
			this->_expression.push(lhs / rhs);
			break;
	}
	this->_stack_count++;
}


// ------------------------------------------------------------------------


// INFO: main program runner's
// ------------------------------------------------------------------------
void	RPN::evaluateExpression(const std::string& input) {
	if (input.length() == 1 && std::isdigit(input[0])) {
		std::cout << input << std::endl;
		return;
	} else if (input.length() == 0) {
		throw std::runtime_error("input is empty!");
	}

	this->_input = input;
	this->_current = this->_input.begin();
	this->_stack_count = 0;

	while (this->_current != this->_input.end()) {
		if (std::isdigit(*this->_current)) {
			consumeDigit();
		} else if (isOperation()) {
			consumeOperation();
			evaluateTopTwoElements();
		} else {
			std::stringstream ss_err;
			ss_err <<"unexpected token: '" << *this->_current << "'";
			throw std::runtime_error(ss_err.str());
		}
	}

	if (this->_stack_count != 1) {
		std::string	err = "invalid expression (too many operands, insufficient operators)!";
		throw std::runtime_error(err);
	}

	int	result = this->_expression.top();
	std::cout << result << std::endl;
}
// ------------------------------------------------------------------------
