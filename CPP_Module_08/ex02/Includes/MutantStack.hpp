#pragma once

#include <deque>
#include <stack>
template<typename T, typename Sequence = std::deque<T> >
class MutantStack : public std::stack<T, Sequence> {
public:
	MutantStack() : std::stack<T, Sequence>() {};

	MutantStack(const Sequence& sequence) :
		std::stack<T, Sequence>(sequence) {}

	MutantStack(const MutantStack& other) :
		std::stack<T, Sequence>(other) {}

	MutantStack& operator=(const MutantStack& other) {
		if (this == &other) {
			return *this;
		}
		std::stack<T, Sequence>::operator=(other);
		return *this;
	}

	~MutantStack() {}
	
	// INFO: types of iterators
	typedef typename std::stack<T, Sequence>::container_type::iterator iterator;
	typedef typename std::stack<T, Sequence>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T, Sequence>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T, Sequence>::container_type::const_reverse_iterator const_reverse_iterator;
	




	// INFO: iterator functions
	iterator	begin() {
		return this->c.begin();
	}

	const_iterator	begin() const {
		return this->c.begin();
	}

	iterator	end() {
		return this->c.end();
	}

	const_iterator	end() const {
		return this->c.end();
	}

	reverse_iterator	rbegin() {
		return this->c.rbegin();
	}

	const_reverse_iterator	rbegin() const {
		return this->c.rbegin();
	}

	reverse_iterator	rend() {
		return this->c.rend();
	}

	const_reverse_iterator	rend() const {
		return this->c.rend();
	}
};
