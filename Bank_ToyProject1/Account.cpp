#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

Account::Account(int id, int money, char* name)
	:accID(id),balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}
Account::Account(const Account& ref)
	:accID(ref.accID),balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const
{
	return accID;
}
void Account::Deposit(int money)
{
	balance += money;
}
int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;
	balance -= money;
}
void Account::ShowAccInfo() const
{
	cout << "°í°´¸í:" << cusName << '\n';
	cout << "°èÁÂ¹øÈ£:" << accID << '\n';
	cout << "°èÁÂ ÀÜ¾×:" << balance << '\n';
}
void Account::GetBalance() const
{
	cout << "°èÁÂÀÜ¾×:" << balance << '\n';
}
Account::~Account()
{
	delete[] cusName;
}
