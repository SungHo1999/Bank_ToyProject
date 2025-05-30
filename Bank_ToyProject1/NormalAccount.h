#ifndef _NOR_ACC_H
#define _NOR_ACC_H
#include "Account.h"
class NormalAccount :public Account //보통 예금 계좌
{
private:
	int interRate; //이자율 %단위
public:
	NormalAccount(int id,int money,char *name,int rate);
	virtual void Deposit(int money);
};
#endif
