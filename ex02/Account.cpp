#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Définition des membres statiques
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructeur
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}

// Destructeur
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}

// Dépôt
void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";deposit:" << deposit
	          << ";amount:" << _amount
	          << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Retrait
bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << _amount;

	if (withdrawal > _amount) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
	          << ";amount:" << _amount
	          << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

// Affiche les infos globales
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	          << ";total:" << _totalAmount
	          << ";deposits:" << _totalNbDeposits
	          << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Affiche l'état d’un compte
void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Accesseurs
int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

int Account::checkAmount(void) const { return _amount; }

// Affiche l’horodatage
void Account::_displayTimestamp(void) {
	std::time_t t = std::time(NULL);
	std::tm *now = std::localtime(&t);

	std::cout << "[" << (now->tm_year + 1900)
	          << std::setfill('0') << std::setw(2) << now->tm_mon + 1
	          << std::setw(2) << now->tm_mday << "_"
	          << std::setw(2) << now->tm_hour
	          << std::setw(2) << now->tm_min
	          << std::setw(2) << now->tm_sec << "] ";
}
