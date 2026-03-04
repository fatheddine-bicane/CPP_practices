#include "../Includes/PmergeMe.hpp"
#include <algorithm>
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

std::vector<PmergeMe::Element>
PmergeMe::pairAndCompareElements(std::vector<Element> input, Element& unpaired, bool& is_odd) {
	std::vector<Element>	winners;
	std::vector<Element>::iterator	it = input.begin();

	// check if the input is odd
	std::vector<Element>::iterator	end = input.end();
	if (input.size() % 2 != 0) {
		end--;
		unpaired = *end;
		unpaired.s = u;
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



void	PmergeMe::updateJacobsthalBounds(int& stop, int& start) {
	stop++;
	start++;
    int next_start = start + 2 * stop;

    stop = start - 1;
    start = next_start - 1;
}


// function should take the new array (made of the winners)
std::vector<PmergeMe::Element>
PmergeMe::mergeIsertSort(std::vector<Element> input) {

	std::vector<Element>	winners;
	std::vector<Element>	main_chain;
	Element				unpaired;
	bool	is_odd;


	// // return at the deepest recursion level since an array of size 1 is sorted!
	if (input.size() <= 1) {
		return input;
	}

	// create pairs and form a chain of the greatest of each pair
	winners = pairAndCompareElements(input, unpaired, is_odd);

	// // recusive call until the input array size is 1 (wich is sorted)
	main_chain = mergeIsertSort(winners);


	// map the losers to the the main chaing possition
	std::vector<Element>	pending_losers;
	std::vector<Element>::iterator it = main_chain.begin();
	std::vector<Element>::iterator end = main_chain.end();
	for (int i = 0; it != end; it++, i++) {
		Element tethered_loser = *(it->tethered_losers.end() - 1);
		it->tethered_losers.erase(it->tethered_losers.end() - 1);
		tethered_loser.s = b;
		tethered_loser.index = i;
		pending_losers.push_back(tethered_loser);
	}

	// if there is an unpaired element append it to the end of the losers
	if (is_odd) {
		unpaired.s = u;
		pending_losers.push_back(unpaired);
	}

	// map the main chain element
	for (size_t i = 0; i < main_chain.size(); i++) {
		main_chain[i].s = a;
		main_chain[i].index = i;
	}






	// append the first loser (b1) to the front of the main chain
	// BUG: check if there are losers (rolling back at the first recursion level there should be no losers)
	main_chain.insert(main_chain.begin(), *pending_losers.begin());



	// using the jacobsthal sequence group elements to push and binary inset them
	int	stop = 0;
	int start = 2;

	// normilize the index
	if (start >= static_cast<int>(pending_losers.size())) {
		start = pending_losers.size() - 1;
	}

	for (;;) {
		// update index
		int	index = start;

		// isert the elements from start until we hit stop
		while (index != stop) {

			// ...



			// find the upper bound in the main chain
			std::vector<Element>::iterator upper_bound = main_chain.end();

			std::vector<Element>::iterator it = main_chain.begin();
			std::vector<Element>::iterator end = main_chain.end();

			for (; it != end; it++) {
				if (it->s == a && it->index == index) {
					upper_bound = it;
					break;
				}
			}

			// the upper painding has no previous pair so the binary search should cover the entier chain
			if (upper_bound == main_chain.end() && is_odd) {
				upper_bound = main_chain.end();
			}


			// binary insert pending_losers[index] in the main chain
			//	while respecting the upper bound
			std::vector<Element>::iterator possition;
			possition = std::lower_bound(main_chain.begin(), upper_bound, pending_losers[index]);
			main_chain.insert(possition, pending_losers[index]);

			// ...



			index--;
		}


		//get the next index
		updateJacobsthalBounds(stop, start);

		// exit the loop if all losers where apended
		if (stop >= static_cast<int>(pending_losers.size() - 1)) {
			break;
		}

		// normilize the starting index and keep going ...
		if (start >= static_cast<int>(pending_losers.size())) {
			start = pending_losers.size() - 1;
		}
	}

	return main_chain;
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
	std::vector<Element> sorted = mergeIsertSort(this->_vSequence);





	std::cout << "sorting ..." << std::endl;
	std::cout << "[";
	for (int i = 1; i < argc; i++) {
		std::cout << sorted[i - 1].winner_value;
		if (i + 1 < argc) {
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;




}
// -----------------------------------------------------------------------------------------
