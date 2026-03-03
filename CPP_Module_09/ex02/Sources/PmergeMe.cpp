#include "../Includes/PmergeMe.hpp"
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>


// INFO: pasring
// -----------------------------------------------------------------------------------------
void	PmergeMe::checkAndThrowParseError(long value, char* end, std::string argv, int arg_pos) {
	std::stringstream	ss_err;
	ss_err << "argument: " << arg_pos << " => '" << argv << "'\n	";

	if (*end != '\0') {
		ss_err << "is not a number!";
		throw std::runtime_error(ss_err.str());
	} else if (value > UINT_MAX) {
		ss_err << "exceed the unsigned integer limits!";
		throw std::runtime_error(ss_err.str());
	} else if (value < 0) {
		ss_err << "program accept only positive values!";
		throw std::runtime_error(ss_err.str());
	}
}


void	PmergeMe::parseArguments(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		char*	end = NULL;
		long	value = std::strtol(argv[i], &end, 10);
		
		checkAndThrowParseError(value, end, argv[i], i);

		// append the value to vector and dqueue
		Element	element;
		element.winner_value = static_cast<int>(value);
		this->_vSequence.push_back(element);
	}
}
// -----------------------------------------------------------------------------------------


// INFO: applying the algorithm
// -----------------------------------------------------------------------------------------

// void	PmergeMe::appendValue() {
// 	// std::vector<std::pair<int, std::pair<sequence, int> > >	tmp;
// 	//
// 	// tmp.push_back({10, {a, 0}});
// }

std::vector<PmergeMe::Element>
PmergeMe::pairAndCompareElements(std::vector<Element> input, Element& unpaired, bool& is_odd) {
	std::vector<Element>	winners;
	std::vector<Element>::iterator	it = input.begin();

	// check if the input is odd
	std::vector<Element>::iterator	end = input.end();
	if (input.size() % 2 != 0) {
		end--;
		unpaired = *end;
		is_odd = true;
	} else {
		is_odd = false;
	}

	for (; it != end; it++) {
		Element	a = *it;
		it++;
		Element	b = *it;

		//pair and compare
		Element tmp;
		if (a.winner_value > b.winner_value) {
			tmp.winner_value = a.winner_value;
			tmp.tethered_losers = a.tethered_losers;
			tmp.tethered_losers.push_back(b);
		} else {
			tmp.winner_value = b.winner_value;
			tmp.tethered_losers = b.tethered_losers;
			tmp.tethered_losers.push_back(a);
		}

		winners.push_back(tmp);
	}
	return winners;
}

// function should take the new array (made of the winners)
void	PmergeMe::mergeIsertSort(std::vector<Element> input) {

	std::vector<Element>	winners;
	Element				unpaired;
	bool	is_odd;

	// create pairs and
	winners = pairAndCompareElements(input, unpaired, is_odd);

	// recusive call until the input array size is 1 (wich is sorted)
	// WARNING: should check agains 0 if the original input is empty
	if (winners.size() > 1) {
		// winners = pairAndCompareElements(winners, unpaired, is_odd);
		mergeIsertSort(winners);
	}



}









void	PmergeMe::applyAlgorithm(int argc, char** argv) {

	// print arguments
	std::cout << "[";
	for (int i = 1; i < argc; i++) {
		std::cout << argv[i];
		if (i + 1 < argc) {
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;


	parseArguments(argc, argv);
	mergeIsertSort(this->_vSequence);

}
// -----------------------------------------------------------------------------------------
