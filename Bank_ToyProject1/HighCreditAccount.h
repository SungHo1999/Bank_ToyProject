#ifndef _HICRD_ACC_H
#define _HICRD_ACC_H
#include "Account.h"
#include "NormalAccount.h"
class HighCreditAccount:public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int id, int money, char* name, int rate,int special);
	virtual void Deposit(int money);
};
#endif 

