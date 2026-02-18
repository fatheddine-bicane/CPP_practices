#include <iostream>
#include <vector>
#include <exception>
#include "../Includes/Span.hpp"

void printHeader(std::string title) {
    std::cout << "\n===================================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "===================================================" << std::endl;
}

int main() {
    printHeader("TEST 1: The Subject's Example");
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span:  " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    printHeader("TEST 2: Adding 10,000 Numbers via Iterators");
    try {
        Span bigSpan(10005);
        std::vector<int> randomNumbers;
        for (int i = 0; i < 10000; i++) {
            randomNumbers.push_back(i+1);
        }

        std::cout << "Adding 10,000 numbers at once..." << std::endl;
        bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span:  " << bigSpan.longestSpan() << std::endl;

        std::cout << "Adding one manual number (42)..." << std::endl;
        bigSpan.addNumber(42); 
        std::cout << "Success." << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    printHeader("TEST 3: Edge Cases (Duplicates & Limits)");
    try {
        Span limitSpan(5);
        limitSpan.addNumber(42);
        limitSpan.addNumber(42);
        limitSpan.addNumber(100);
        std::cout << "Shortest Span (Expect 0): " << limitSpan.shortestSpan() << std::endl;
        limitSpan.addNumber(1);
        limitSpan.addNumber(2);
        std::cout << "Items currently: 5/5" << std::endl;
        std::cout << "Trying to add 6th item (Expect Exception)..." << std::endl;
        limitSpan.addNumber(999);
    } catch (std::exception &e) {
        std::cout << "Caught Expected Error: " << e.what() << std::endl;
    }


    printHeader("TEST 4: Exception - Not Enough Numbers");
    try {
        Span emptySpan(5);
        emptySpan.addNumber(10);
        std::cout << "Trying shortestSpan with 1 element (Expect Exception)..." << std::endl;
        std::cout << emptySpan.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught Expected Error: " << e.what() << std::endl;
    }
}
