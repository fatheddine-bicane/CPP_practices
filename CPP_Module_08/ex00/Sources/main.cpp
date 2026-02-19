#include <iostream>
#include <list>
#include <vector>
#include "../Includes/easyfind.hpp"

void printTestHeader(const std::string& title) {
	std::cout << "===================================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "===================================================" << std::endl;
}

int main() {
	std::vector<int> arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	printTestHeader("                   VECTORS");

	printTestHeader("TEST 1: Vector - Searching for existing value (40)");

	std::cout << "Calling easyfind(arr, 40)..." << std::endl;
	std::vector<int>::iterator vecIt = easyfind(arr, 40);
	if (vecIt != arr.end()) {
		std::cout << "SUCCESS: Value found: " << *vecIt << std::endl;
	} else {
		std::cout << "FAILURE: Value not found!" << std::endl;
	}
	std::cout << std::endl;



	printTestHeader("TEST 2: Vector - Searching for missing value (99)");
	std::cout << "Calling easyfind(arr, 99)..." << std::endl;
	vecIt = easyfind(arr, 99);
	if (vecIt != arr.end()) {
		std::cout << "SUCCESS: Value found: " << *vecIt << std::endl;
	} else {
		std::cout << "FAILURE: Value not found!" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	printTestHeader("                     LISTS");






	std::list<int> myList;
	myList.push_back(100);
	myList.push_back(200);
	myList.push_back(300);

	printTestHeader("TEST 3: List - Searching for existing value (200)");
	std::cout << "Calling easyfind(myList, 200)..." << std::endl;
	std::list<int>::iterator listIt = easyfind(myList, 200);
	if (listIt != myList.end()) {
		std::cout << "SUCCESS: Value found: " << *listIt << std::endl;
	} else {
		std::cout << "FAILURE: Value not found!" << std::endl;
	}
	std::cout << std::endl;


	printTestHeader("TEST 4: List - Searching for missing value (500)");
	std::cout << "Calling easyfind(myList, 500)..." << std::endl;
	listIt = easyfind(myList, 500);
	if (listIt != myList.end()) {
		std::cout << "Value found: " << *listIt << std::endl;
	} else {
		std::cout << "FAILURE: Value not found!" << std::endl;
	}
	std::cout << "===================================================" << std::endl;

	return 0;
}
