#include "./Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "index:" << this->_accountIndex <<";";
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	std::cout << "amount:" << this->_amount <<";created\n";
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

int	Account::getNbAccounts() {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ){
	return _totalAmount;
}

int	Account::getNbDeposits( void ){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
		<< "total:" << Account::getTotalAmount() << ";"
		<< "deposite:" << Account::getNbDeposits() << ";"
		<< "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (this->_amount < withdrawal) {
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "withdrawal:refused\n";
		return false;
	}
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << "\n";
	Account::_totalNbWithdrawals++;
	return true;
}

int	Account::checkAmount() const {
	return this->_amount;
}

void	Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << "\n";
}

void	Account::_displayTimestamp() {
	time_t		curentTime = time(NULL);
	struct tm	*localTime = localtime(&curentTime);
	char	timeBuffer[16];
	strftime(timeBuffer, 16, "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << timeBuffer << "] ";
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" 
		<< "amount:" << this->_amount << ";closed\n";
};
