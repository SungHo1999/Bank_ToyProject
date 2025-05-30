#include <iostream>
#include "HighCreditAccount.h"


HighCreditAccount::HighCreditAccount(int id,int money,char *name,int rate,int special)
	:NormalAccount(id,money,name,rate),specialRate(special)
{}
void HighCreditAccount::Deposit(int money)
{
	NormalAccount::Deposit(money); //���ݰ� ���� �߰�
	Account::Deposit(money * (specialRate / 100.0)); //Ư�� ���� �߰�
}