#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

// Static member variable initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Current time in [YYYYMMDD_HHMMSS] format
void Account::_displayTimestamp(void)
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[19];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 18, "[%Y%m%d_%H%M%S]", timeinfo);
    std::cout << buffer << " ";
}

// Number of accounts
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

// Total amount
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

// Number of deposits
int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

// Number of withdrawals
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

// Display accounts information
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

// Default constructor (private)
Account::Account(void)
    : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
}

// Constructor with initial deposit
Account::Account(int initial_deposit)
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

// Destructor
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

// Deposit
void Account::makeDeposit(int deposit)
{
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

// Withdraw
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;

    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return true;
}

// Check amount
int Account::checkAmount(void) const
{
    return _amount;
}

// Display account status
void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}
