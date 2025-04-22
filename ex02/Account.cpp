/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:34:47 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/22 14:32:57 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit)
  : _accountIndex(_nbAccounts)
  , _amount(initial_deposit)
  , _nbDeposits(0)
    , _nbWithdrawals(0)
{
  ++_nbAccounts;
  _totalAmount += _amount;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
    << ";amount:" << _amount
    << ";created" << std::endl;
}

Account::~Account()
{
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
    << ";amount:" << _amount
    << ";closed" << std::endl;
  --_nbAccounts;
  _totalAmount -= _amount;
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos()
{
  _displayTimestamp();
  std::cout << " accounts:" << getNbAccounts()
    << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals()
    << std::endl;
}

void Account::makeDeposit(int deposit)
{
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
    << ";p_amount:" << _amount
    << ";deposit:" << deposit;

  _amount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  _totalAmount += deposit;

  std::cout << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits
    << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
    << ";p_amount:" << _amount
    << ";withdrawal:";

  if (withdrawal > _amount) {
    std::cout << "refused" << std::endl;
    return false;
  }

  _amount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  _totalAmount -= withdrawal;

  std::cout << withdrawal
    << ";amount:" << _amount
    << ";nb_withdrawals:" << _nbWithdrawals
    << std::endl;
  return true;
}

int Account::checkAmount() const { return _amount; }

void Account::displayStatus() const
{
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals
    << std::endl;
}

void Account::_displayTimestamp()
{
  time_t now = std::time(NULL);
  struct tm timenow = *std::localtime(&now);

  std::cout << "[" << timenow.tm_year + 1900 <<
    std::setfill('0') << std::setw(2) << timenow.tm_mon + 1 <<
    std::setfill('0') << std::setw(2) << timenow.tm_mday << "_" <<
    std::setfill('0') << std::setw(2) << timenow.tm_hour <<
    std::setfill('0') << std::setw(2) << timenow.tm_min <<
    std::setfill('0') << std::setw(2) << timenow.tm_sec <<
    "]";

  // std::cout << "[19920104_091532]";
}
