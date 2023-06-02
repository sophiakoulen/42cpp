/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:06:46 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 11:49:48 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	cout
		<<"accounts:"<<Account::_nbAccounts<<";"
		<<"total:"<<Account::_totalAmount<<";"
		<<"deposits:"<<Account::_totalNbDeposits<<";"
		<<"withdrawals:"<<Account::_totalNbWithdrawals
		<<endl;
}

Account::Account(int initial_deposit):
	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	cout
		<<"index:"<<this->_accountIndex<<";"
		<<"amount:"<<this->_amount<<";"
		<<"created"<<endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	cout
		<<"index:"<<this->_accountIndex<<";"
		<<"amount:"<<this->_amount<<";"
		<<"closed"<<endl;

	Account::_totalAmount -= this->_amount;
	Account::_nbAccounts--;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	cout
		<<"index:"<<this->_accountIndex<<";"
		<<"p_amount:"<<this->_amount<<";"
		<<"deposit:"<<deposit<<";";

	this->_amount += deposit;
	this->_nbDeposits++;

	cout
		<<"amount:"<<this->_amount<<";"
		<<"nb_deposits:"<<this->_nbDeposits
		<<endl;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	cout
		<<"index:"<<this->_accountIndex<<";"
		<<"p_amount:"<<this->_amount<<";"
		<<"withdrawal:";

	if (this->_amount < withdrawal)
	{
		cout<<"refused"<<endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	cout
		<<"amount:"<<this->_amount<<";"
		<<"nb_withdrawals:"<<this->_nbWithdrawals
		<<endl;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	cout
		<<"index:"<<this->_accountIndex<<";"
		<<"amount:"<<this->_amount<<";"
		<<"deposits:"<<this->_nbDeposits<<";"
		<<"withdrawals:"<<this->_nbWithdrawals
		<<endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::time_t	t;
	std::tm		*now;
	char		buf[64];

	t = std::time(0);
	now = std::localtime(&t);
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", now);
	cout<<buf;
}

Account::Account(void)
{
	return ;
}