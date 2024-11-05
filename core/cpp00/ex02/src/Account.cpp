#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts  = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposists  = 0;
int Account::_totalNbWIthdrawals  = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = intital_deposit;
	_nbDepoists = 0;
	_nbWithdrawals = 0;
    _nbAccounts++;
	_totalAmount += _amount;
	_totalNbDeposists++;//does it count the inital depoist

	std::cout << _displayTimeStamp() << " " << "index:" << _accountIndex 
	<< ";" << "amount:" << _amount << ";" << "created" << std::endl;
}

static int	getNbAccounts(void)
{
	return(_nbAccounts);
}

static int	getTotalAmount(void)
{
	return(_totalAmount);
}

static int	getNbDeposits(void)
{
	return(_totalNbDeposits);
}

static int	getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

static void	displayAccountInfos(void)
{
	std::cout << _displayTimeStamp() << " " << "accounts:" << getNbAccounts() 
		<< ";" << "total:" << getTotalAmount() << ";";
		<< ";" << "deposit:" << getNbDeposits() << ";";
		<< ";" << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	makeDepoist(int depoist)
{
	_amount += depoist;
	_nbDeposits++;

}

bool makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal >= 0) 
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		return (true);
	}
	else
		return (false);
}

int	checkAmount(void) const
{
	return (0);
}

void	displayStatus(void) const
{
	std::cout << _displayTimeStamp() <<  " index:" << _accountIndex 
	<< ";" << "amount:" << _amount << ";" << "depoist:" <<
	 _amount << ";" << "withdrawals:" << std::endl;
}

static void	_displayTimestamp(void)
{

}

Account::~Account(void)
{
	std::cout << _displayTimeStamp() << " index:" << _accountIndex 
	<< ";" << "amount:" << _amount << ";" << "closed" << std::endl;
	_nbAccounts--;
}
