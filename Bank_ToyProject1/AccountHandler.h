#ifndef _ACC_HAND_H
#define _ACC_HAND_H
#include "Account.h"
const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class AccountHandler
{
private:
	Account* accArr[100] = {};
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};
#endif
