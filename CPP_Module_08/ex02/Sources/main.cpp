#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include "../Includes/MutantStack.hpp"

// Helper to print separators
void printHeader(std::string title) {
    std::cout << "\n-----------------------------------" << std::endl;
    std::cout << title << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

int main()
{
    printHeader("TEST 1: Subject Logic (MutantStack)");
    {
        MutantStack<int, std::vector<int> > mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "Top: " << mstack.top() << std::endl; // 17
        mstack.pop();
        std::cout << "Size: " << mstack.size() << std::endl; // 1
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
        MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "Stack Elements:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int, std::vector<int> > s(mstack);
    }

    printHeader("TEST 2: Subject Logic (std::list)");
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << "Top: " << mstack.back() << std::endl; // 17
        mstack.pop_back();
        std::cout << "Size: " << mstack.size() << std::endl; // 1
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "List Elements:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    printHeader("TEST 3: Reverse Iterators");
    {
        MutantStack<char> letters;
        letters.push('A');
        letters.push('B');
        letters.push('C');
        letters.push('D');

        std::cout << "Normal Order (begin -> end):" << std::endl;
        for (MutantStack<char>::iterator it = letters.begin(); it != letters.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Reverse Order (rbegin -> rend):" << std::endl;
        for (MutantStack<char>::reverse_iterator rit = letters.rbegin(); rit != letters.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
