#include "Account.hpp"
# include <iostream>
# include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

Account::Account( int initial_deposit )
{
	static int	index = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;
	this->_accountIndex = index++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << (_amount += deposit) << ";";
	std::cout << "nb_deposits:" << ++_nbDeposits << std::endl;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (_amount - withdrawal < 0)
		return (std::cout << "withdrawal:refused" << std::endl, 1);
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << (_amount -= withdrawal) << ";";
	std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	return (0);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	_displayTimestamp( void )
{
	std::time_t now = std::time(nullptr);
	std::tm		*localTime = std::localtime(&now);

	std::cout	<< "[" << localTime->tm_year + 1900
				<< localTime->tm_mon + 1
				<< localTime->tm_mday
				<< "_"
				<< localTime->tm_hour
				<< localTime->tm_min
				<< localTime->tm_sec;
}

