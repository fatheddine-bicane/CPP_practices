#pragma once

#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
class PmergeMe {

private:

	typedef enum {
		a, b, u
	} sequence;

	struct Element {
		unsigned int			winner_value;
		sequence				s;
		int						index;
		std::vector<Element>	tethered_losers;

		bool operator<(const Element& other) const {
			return this->winner_value < other.winner_value;
		}
	};


	std::vector<Element>	_vSequence;
	std::deque<Element>		_dSequence;
	struct timeval _start;
	struct timeval _end;


	template<typename SequenceType>
	SequenceType pairAndCompareElements(SequenceType input, Element& unpaired, bool& is_odd) {
		SequenceType	winners;

		typename SequenceType::iterator it = input.begin();
		typename SequenceType::iterator end = input.end();
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

	template <typename SequenceType>
	void	mapLosersElementsToWinners(SequenceType& main_chain,
								 SequenceType& pending_losers
								 , Element& unpaired, bool is_odd) {

		typename SequenceType::iterator it = main_chain.begin();
		typename SequenceType::iterator end = main_chain.end();
		for (int i = 0; it != end; it++, i++) {
			Element tethered_loser = *(it->tethered_losers.end() - 1);
			it->tethered_losers.erase(it->tethered_losers.end() - 1);
			tethered_loser.s = b;
			tethered_loser.index = i;
			pending_losers.push_back(tethered_loser);
		}

		if (is_odd) {
			unpaired.s = u;
			pending_losers.push_back(unpaired);
		}

		// map the main chain element
		for (size_t i = 0; i < main_chain.size(); i++) {
			main_chain[i].s = a;
			main_chain[i].index = i;
		}
	}

	template <typename SequenceType>
	void	binaryInsertLoser(SequenceType& main_chain,
						 int index, bool is_odd, Element& loser) {

		typename SequenceType::iterator mapped_winner;

		if (is_odd) {
			mapped_winner = main_chain.end();
		} else {
			typename SequenceType::iterator  it = main_chain.begin();
			typename SequenceType::iterator  end = main_chain.end();
			for (; it != end; it++) {
				if (it->s == a && it->index == index) {
					mapped_winner = it;
					break;
				}
			}
		}

		typename SequenceType::iterator possition;
		possition = std::lower_bound(main_chain.begin(), mapped_winner, loser);
		main_chain.insert(possition, loser);
	}

	template <typename SequenceType>
	void	normalizeStartIndex(int& start, SequenceType& pending_losers) {
		if (start >= static_cast<int>(pending_losers.size())) {
			start = pending_losers.size() - 1;
		}
	}


	template <typename SequenceType>
	void	insertLosersInMainChain(SequenceType& main_chain,
							  SequenceType& pending_losers, bool is_odd) {

		int	stop = 0;
		int start = 2;

		normalizeStartIndex(start, pending_losers);

		for (;;) {
			int	index = start;

			while (index != stop) {
				binaryInsertLoser(main_chain, index, is_odd, pending_losers[index]);
				index--;
			}

			updateJacobsthalBounds(stop, start);

			if (stop >= static_cast<int>(pending_losers.size() - 1)) {
				break;
			}

			normalizeStartIndex(start, pending_losers);
		}
	}


	template <typename SequenceType>
	void	printArgument(bool is_sorted, SequenceType& container) {
		if (is_sorted == true) {
			std::cout << "After:  ";
		} else {
			std::cout << "Before: ";
		}

		int end = container.size();
		for (int i = 0; i < end; i++) {
			std::cout << container[i].winner_value << ' ';
		}
		std::cout << std::endl;
	}


	double	calculateTimeSpent(bool get_diff);
	void	updateJacobsthalBounds(int& stop, int& start);
	std::vector<Element>	VectorMergeIsertSort(std::vector<Element>& input);
	std::deque<Element>		DequeMergeInsetSort(std::deque<Element> input);

	// INFO: parsing functions
	void	checkAndThrowParseError(long value, char* end, std::string argv, int arg_pos);
	void	parseArguments(int argc, char** argv);


public:
	// INFO: orthodox canonical
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& other);
	~PmergeMe();

	void	applyAlgorithm(int argc, char** argv);
	
};
