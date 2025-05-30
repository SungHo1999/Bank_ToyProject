#ifndef _ACC_HAND_H
#define _ACC_HAND_H
#include "Account.h"
const int NAME_LEN = 20;

//사용자 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//신용등급
enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};
//계좌 종류
enum {NORMAL=1, CREDIT=2};

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
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};
#endif
