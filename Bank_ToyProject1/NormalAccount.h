#ifndef _NOR_ACC_H
#define _NOR_ACC_H
#include "Account.h"
class NormalAccount :public Account //���� ���� ����
{
private:
	int interRate; //������ %����
public:
	NormalAccount(int id,int money,char *name,int rate);
	virtual void Deposit(int money);
};
#endif
