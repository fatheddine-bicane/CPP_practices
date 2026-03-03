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
		std::vector<Element>	tethered_losers;
	};

	std::vector<Element>	_vSequence;


	void	checkAndThrowParseError(long value, char* end, std::string argv, int arg_pos);
	void	parseArguments(int argc, char** argv);



	// void	appendValue();
	std::vector<Element>
	pairAndCompareElements(std::vector<Element> input, Element& unpaired, bool& is_odd);

	void	mergeIsertSort(std::vector<Element> input);

public:
	// INFO: orthodox canonical

	void	applyAlgorithm(int argc, char** argv);
	
};
