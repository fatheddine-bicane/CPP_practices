#pragma once

#include <string>
#include <vector>
class PmergeMe {

private:

	typedef enum {
		a, b
	} sequence;

	struct Element {
		int	winner_value;
		sequence	s;
		int			index;
		std::vector<Element>	tethered_losers;

		// The overloaded operator< definition
		bool operator<(const Element& other) const {
			return this->winner_value < other.winner_value;
		}
		// TODO: might need a '<=' operator for inputs with equal elements
	};

	std::vector<Element>	_vSequence;


	void	checkAndThrowParseError(long value, char* end, std::string argv, int arg_pos);
	void	parseArguments(int argc, char** argv);



	// void	appendValue();
	std::vector<Element>
	pairAndCompareElements(std::vector<Element> input, Element& unpaired, bool& is_odd);


	// apply algorithm
	void updateJacobsthalBounds(int& stop, int& start);

	std::vector<Element>	mergeIsertSort(std::vector<Element> input);

public:
	// INFO: orthodox canonical

	void	applyAlgorithm(int argc, char** argv);
	
};
