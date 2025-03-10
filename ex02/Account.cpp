// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

// 静的メンバ変数の初期化
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// 現在の時刻を [YYYYMMDD_HHMMSS] 形式で表示
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

// アカウント数の取得
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

// 総額の取得
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

// 入金回数の取得
int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

// 出金回数の取得
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

// アカウント情報の表示
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

// デフォルトコンストラクタ（private）
Account::Account(void)
    : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
}

// 初期入金付きコンストラクタ
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

// デストラクタ
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

// 入金処理
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

// 出金処理
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

// 残高確認
int Account::checkAmount(void) const
{
    return _amount;
}

// アカウント状態の表示
void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}
