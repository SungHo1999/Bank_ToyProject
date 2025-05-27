#ifndef _ACC_H
#define _ACC_H

class Account
{
private:
	int accID;// 계좌번호
	int balance;//잔고
	char* cusName; //고객명
public:
	Account(int id, int money, char* name);
	Account(const Account& ref);

	int GetAccID() const;
	void Deposit(int money); //예금
	int Withdraw(int money); //출금
	void ShowAccInfo() const;
	void GetBalance() const; //잔액확인
	~Account();
};
#endif