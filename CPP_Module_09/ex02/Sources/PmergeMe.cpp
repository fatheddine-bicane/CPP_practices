#include "../Includes/PmergeMe.hpp"
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/select.h>
#include <vector>

// INFO: orthodox canonical
// -----------------------------------------------------------------------------------------
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void) other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void) other;
	return *this;
}

PmergeMe::~PmergeMe() {}

// -----------------------------------------------------------------------------------------

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
		element.winner_value = static_cast<unsigned int>(value);
		this->_vSequence.push_back(element);
		this->_dSequence.push_back(element);
	}
}
// -----------------------------------------------------------------------------------------


// INFO: applying the algorithm
// -----------------------------------------------------------------------------------------


void	PmergeMe::updateJacobsthalBounds(int& stop, int& start) {
	stop++;
	start++;
    int next_start = start + 2 * stop;

    stop = start - 1;
    start = next_start - 1;
}

std::vector<PmergeMe::Element>
PmergeMe::VectorMergeIsertSort(std::vector<Element>& input) {
	if (input.size() <= 1) {
		return input;
	}

	std::vector<Element>	main_chain;

	Element	unpaired;
	bool	is_odd;
	main_chain = pairAndCompareElements(input, unpaired, is_odd);

	main_chain = VectorMergeIsertSort(main_chain);

	std::vector<Element>	pending_losers;
	mapLosersElementsToWinners(main_chain, pending_losers, unpaired, is_odd);

	// append the first loser (b1) to the front of the main chain
	main_chain.insert(main_chain.begin(), *pending_losers.begin());

	insertLosersInMainChain(main_chain, pending_losers, is_odd);

	return main_chain;
}

std::deque<PmergeMe::Element>
PmergeMe::DequeMergeInsetSort(std::deque<Element> input) {
	if (input.size() <= 1) {
		return input;
	}

	std::deque<Element>	main_chain;

	Element	unpaired;
	bool	is_odd;
	main_chain = pairAndCompareElements(input, unpaired, is_odd);

	main_chain = DequeMergeInsetSort(main_chain);

	std::deque<Element>	pending_losers;
	mapLosersElementsToWinners(main_chain, pending_losers, unpaired, is_odd);

	// append the first loser (b1) to the front of the main chain
	main_chain.push_front(*pending_losers.begin());

	insertLosersInMainChain(main_chain, pending_losers, is_odd);

	return main_chain;
}

double PmergeMe::calculateTimeSpent(bool get_diff) {
	if (get_diff == false) {
		gettimeofday(&this->_start, NULL);
		return 0;
	}

	gettimeofday(&this->_end, NULL);

	long	seconds = this->_end.tv_sec - this->_start.tv_sec;
	long	useconds = this->_end.tv_usec - this->_start.tv_usec;

	double	total_microseconds = (seconds * 1000000.0) + useconds;
	return total_microseconds;
}



void	PmergeMe::applyAlgorithm(int argc, char** argv) {
	parseArguments(argc, argv);
	printArgument(false, this->_vSequence);

	// vector sorting
	calculateTimeSpent(false);
	this->_vSequence = VectorMergeIsertSort(this->_vSequence);
	double vector_time = calculateTimeSpent(true);

	// deque sorting
	calculateTimeSpent(false);
	this->_dSequence = DequeMergeInsetSort(this->_dSequence);
	double deque_time = calculateTimeSpent(true);

	// showcase time spent sorting the input
	printArgument(true, this->_vSequence);
	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::vector : "
			  << vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::deque : "
			  << deque_time << " us" << std::endl;
}
// -----------------------------------------------------------------------------------------
