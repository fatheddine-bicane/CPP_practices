#include <vector>

class Span {
private:
	unsigned int	_size;
	unsigned int	contentCount;
	std::vector<int>	_elements;

public:
	Span();
	Span(unsigned int size);
	Span(const Span& other);
	Span&	operator=(const Span& other);
	~Span();

	void	addNumber(int value);

};
