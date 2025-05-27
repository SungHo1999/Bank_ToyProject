#ifndef _ACC_H
#define _ACC_H

class Account
{
private:
	int accID;// ���¹�ȣ
	int balance;//�ܰ�
	char* cusName; //����
public:
	Account(int id, int money, char* name);
	Account(const Account& ref);

	int GetAccID() const;
	void Deposit(int money); //����
	int Withdraw(int money); //���
	void ShowAccInfo() const;
	void GetBalance() const; //�ܾ�Ȯ��
	~Account();
};
#endif