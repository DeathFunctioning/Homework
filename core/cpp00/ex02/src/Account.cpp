#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	static int index;

	index = 0;

	_accountIndex = index++;
	_amount = intital_deposit;
	_nbDepoists = 0;
	_nbWithdrawals = 0;

	std::cout << _displayTimeStamp() << " " << "index:" << _accountIndex 
	<< ";" << "amount:" << _amount << ";" << "created" << std::endl;
}

static int	getNbAccounts(void)
{
	return();
}

static int	getTotalAmount(void)
{
	return();
}

static int	getNbDeposits(void)
{
	return();
}

static int	getNbWithdrawals(void)
{
	return();
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

}
