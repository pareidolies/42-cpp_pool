/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:53:46 by smostefa          #+#    #+#             */
/*   Updated: 2022/11/11 15:53:48 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

# include <iostream>
# include <iomanip>
# include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
    _amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
              << _amount << ";created" << std::endl;
    _nbAccounts++;
}

Account::~Account()
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
              << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
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
    _displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:"
              << getTotalAmount() << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
              << checkAmount() << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	std::cout << ";amount:" << checkAmount() << ";nb_deposits:"
              << _nbDeposits << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
              << checkAmount() << ";withdrawal:";
    if (_amount >= withdrawal)
    {
	    _amount -= withdrawal;
	    _nbWithdrawals++;
	    std::cout << withdrawal << ";amount:" << checkAmount()
                  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    }
    std::cout << "refused" << std::endl;
    return (false);
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
              << checkAmount() << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t t;	
    tm  *now;

    t = time(NULL);
    now = localtime(&t);
    std::cout << "[" << (now->tm_year + 1900) << std::setfill('0')
              << std::setw(2) << (now->tm_mon + 1) << std::setw(2)
              << now->tm_mday << "_" << std::setw(2) << now->tm_hour
              << std::setw(2) << now->tm_min << std::setw(2)
              << now->tm_sec << "] ";
}
