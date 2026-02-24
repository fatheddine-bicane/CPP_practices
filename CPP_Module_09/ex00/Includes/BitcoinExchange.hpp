#include <map>
#include <vector>

class BitcoinExchange {
private:
	std::map<std::string, float> _db;




	// INFO: validate date input
	bool	isLeapYear(int year);
	bool	isKnuckleMonth(int month);
	bool	isDateValid(int year, int month, int day);
	void	checkDateSyntax(const std::string& date);
	void	parseDate(const std::string& date);

	// INFO: validate value input
	float	parseValue(const std::string& value);

	void	evaluateBtcValue(const std::string& date, float value);

public:
	void	readDataBase();
	void	evaluateInputFile(std::string path);

};
