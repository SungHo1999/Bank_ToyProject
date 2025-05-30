#include <iostream>
#include "NormalAccount.h"
using std::cout;

NormalAccount::NormalAccount(int id, int money, char* name, int rate)
	:Account(id, money, name), interRate(rate)
{}
void NormalAccount::Deposit(int money)
{
	Account::Deposit(money); //원금추가
	Account::Deposit(money * (interRate / 100.0)); //이자 추가
}