#include "../Includes/Span.hpp"
#include <algorithm>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <vector>

Span::Span() :
	_size(10),
	_contentCount(0) {}

Span::Span(unsigned int size) :
	_size(size),
	_contentCount(0) {}

Span::Span(const Span& other) :
	_size(other._size),
	_contentCount(other._contentCount) {
	this->_elements = other._elements;
}

Span& Span::operator=(const Span& other) {
	if (this == &other) {
		return *this;
	}
	this->_size = other._size;
	this->_contentCount = other._contentCount;
	this->_elements = other._elements;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int value) {
	if (this->_contentCount == this->_size) {
		throw std::runtime_error("The span reached full capacity!\n");
	}
	this->_contentCount++;
	this->_elements.push_back(value);
}


int	Span::shortestSpan() {
	if (this->_contentCount <= 1) {
		throw std::runtime_error("the span must contain at least 2 elements!");
	}
	std::vector<int> sorted_elements(this->_elements);
	std::sort(sorted_elements.begin(), sorted_elements.end());
	int shortest = INT_MAX;
	std::vector<int>::iterator it = sorted_elements.begin();
	std::vector<int>::iterator next_it = ++sorted_elements.begin();

	for (;next_it != sorted_elements.end(); it++, next_it++) {
		int a = *it;
		int b = *next_it;
		if (b - a < shortest) {
			shortest = b - a;
		}
	}
	return shortest;
}

int	Span::longestSpan() {
	if (this->_contentCount <= 1) {
		throw std::runtime_error("the span must contain at least 2 elements!");
	}
	std::vector<int> sorted_elements(this->_elements);
	std::sort(sorted_elements.begin(), sorted_elements.end());

	return ((*--sorted_elements.end()) - (*sorted_elements.begin()));
}
