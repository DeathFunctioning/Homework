#include "Account.hpp"
#include <iostream>
#include <ctime>


//Need to build timestamp function currently has placeholder
//Also need to format and pretty up code 

int Account::_nbAccounts  = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits  = 0;
int Account::_totalNbWithdrawals  = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    _nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" << "amount:" << _amount << ";"
	   	<< "created" << std::endl;
	return ;
}

int	Account::getNbAccounts(void)
{
	return(_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return(_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";" << "total:" <<
		getTotalAmount() << ";" << "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

void Account::makeDeposit(int depoist)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" << "p_amount:" <<
		_amount << ";" << "depoist:" << depoist << ";";
	_amount += depoist;
	_totalAmount += depoist;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:" << _amount << ";" << "nb_deposits:" << _nbDeposits
		<< std::endl;
	return ;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal >= 0) 
	{
		_displayTimestamp();
		std::cout <<  " index:" << _accountIndex << ";" << "p_amount:" <<
			_amount << ";" << "withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "amount:" << _amount << ";" << "nb_withdrawals:" <<
			_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout <<  " index:" << _accountIndex << ";" << "p_amount:" <<
			_amount << ";" << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
}

int	Account::checkAmount(void) const 
{
	return (0);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout <<  " index:" << _accountIndex << ";" << "amount:" <<
		_amount << ";" << "depoist:" << _nbDeposits << ";" << "withdrawals:"
		<< _nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	time_t	timestamp;
	struct tm datetime;
	char	timeOutput[18];

	timestamp = time(NULL);
	datetime = *localtime(&timestamp);
	strftime(timeOutput, 18, "[%Y%m%d_%H%M%S]", &datetime);
	std::cout << timeOutput;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout  << " index:" << _accountIndex << ";" << "amount:" << _amount
		<< ";" << "closed" << std::endl;
	_nbAccounts--;
	return ;
}
