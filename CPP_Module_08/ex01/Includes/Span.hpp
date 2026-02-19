#pragma once

#include <iterator>
#include <sstream>
#include <stdexcept>
#include <vector>

class Span {
private:
	unsigned int	_size;
	unsigned int	_contentCount;
	std::vector<int>	_elements;

public:
	Span();
	Span(unsigned int size);
	Span(const Span& other);
	Span&	operator=(const Span& other);
	~Span();

	void	addNumber(int value);
	template<typename Iterator>
	void	addNumber(Iterator begin, Iterator end) {
		long count = std::distance(begin, end);
		if (count + this->_contentCount > this->_size) {
			std::stringstream ss_err;
			ss_err << "The span cannot add '" << count << "' elements!\n";
			throw std::runtime_error(ss_err.str());
		}
		this->_elements.insert(this->_elements.end(), begin, end);
		this->_contentCount += count;
	}
	int	shortestSpan();
	int	longestSpan();

};
