#include "../Includes/Span.hpp"
#include <stdexcept>

Span::Span() :
	_size(10),
	contentCount(0) {}

Span::Span(unsigned int size) :
	_size(size),
	contentCount(0) {}

Span::Span(const Span& other) :
	_size(other._size),
	contentCount(other.contentCount) {
	this->_elements = other._elements;
}

Span& Span::operator=(const Span& other) {
	if (this == &other) {
		return *this;
	}
	this->_size = other._size;
	this->contentCount = other.contentCount;
	this->_elements = other._elements;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int value) {
	if (this->contentCount == this->_size) {
		throw std::runtime_error("The span reached full capacity!\n");
	}
	this->contentCount++;
	this->_elements.push_back(value);
}
