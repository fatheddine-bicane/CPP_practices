#include "../Includes/BitcoinExchange.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>


// INFO: validate date input
// ------------------------------------------------------------------------
bool	BitcoinExchange::isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool	BitcoinExchange::isKnuckleMonth(int month) {
	return (month == 1 || month == 3 || month == 5
			|| month == 7 || month == 8
			|| month == 10 || month == 12);
}


bool	BitcoinExchange::isDateValid(int year, int month, int day) {
	if (!(year >= 2009 && year <= 2022)) return false;
	if (year == 2009 && (month < 1 || day < 2)) return false;
	if (year == 2022 && (month > 3 || day > 29)) return false;
	if (!(month >= 1 && month <= 12) || !(day >= 1 && day <= 31)) return false;
	return true;
}


void	BitcoinExchange::checkDateSyntax(const std::string& date) {
	if (date.length() != 10) {
		throw std::runtime_error("bad date input: " + date + "!\n");
	}
	int	hyphen_count = 0;
	for (int i = 0; i < 10; i++) {
		if (date[i] == '-') {
			if (hyphen_count == 2) {
				throw std::runtime_error("bad date input: " + date + "!\n");
			}
			hyphen_count++;
		} else if (!std::isdigit(date[i])) {
			throw std::runtime_error("bad date input: " + date + "!\n");
		}
	}
}

void	BitcoinExchange::parseDate(const std::string& date) {
	checkDateSyntax(date);

	int	year = std::atoi(date.substr(0, date.find('-')).c_str());
	int month = std::atoi(date.substr(5, 7).c_str());
	int	day = std::atoi(date.substr(8).c_str());

	if (!isDateValid(year, month, day)) {
		throw std::runtime_error("date cannot be used: " + date + "!\n");
	}

	if (month == 2) {
		if (day > 29) {
			throw std::runtime_error("incorrect day number!\n");
		} else if (!isLeapYear(year) && day == 29) {
			throw std::runtime_error("non leap years cannot contain 29 days!\n");
		}
	} else if (!isKnuckleMonth(month) && day == 31) {
		throw std::runtime_error("incorrect day number!\n");
	} else if (isKnuckleMonth(month) && day > 30) {
		throw std::runtime_error("incorrect day number!\n");
	}
}
// ------------------------------------------------------------------------


// INFO: validate date input
// ------------------------------------------------------------------------

float	BitcoinExchange::parseValue(const std::string& value) {
	char*	end = NULL;
	double	numeric_value = strtod(value.c_str(), &end);
	if (end != NULL) {
		throw std::runtime_error("value not valid: '" + value + "'!\n");
	} else if (!(numeric_value >= 0 && numeric_value <= 1000)) {
		throw std::runtime_error("value not valid: '" + value + "'!\n");
	}
	return numeric_value;
}
// ------------------------------------------------------------------------

void	BitcoinExchange::evaluateBtcValue(const std::string& date, float value) {
}

void	BitcoinExchange::readDataBase() {
	std::ifstream db("./DataBase/data.csv");
	if (!db.is_open()) {
		throw std::runtime_error("'data.csv' not found!\n");
	}

	std::string	line;
	std::getline(db, line);

	while (std::getline(db, line)) {
		int			decimal = line.find(',');
		std::string	date = line.substr(0, decimal);
		float		price = std::atof(line.substr(decimal + 1).c_str());
		this->_db[date] = price;
	}

	db.close();
}

void	BitcoinExchange::evaluateInputFile(std::string path) {
	std::ifstream input_file(path);
	if (!input_file.is_open()) {
		throw std::runtime_error("could not open file.\n");
	}

	std::string	line;
	std::getline(input_file, line);

	while (std::getline(input_file, line)) {
		size_t		pipe = line.find(" | ");
		if (pipe == std::string::npos) {
			throw std::runtime_error("Error: bad input => " + line + "\n");
		}

		std::string	date = line.substr(0, pipe);
		try {
			parseDate(date);
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what();
			continue;
		}

		std::string	value = line.substr(pipe + 3);
		try {
			parseValue(value);
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what();
			continue;
		}
	}

	input_file.close();

}








