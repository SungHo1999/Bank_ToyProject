#include <iostream>
#include"AccountHandler.h"
#include"NormalAccount.h"
#include "HighCreditAccount.h"
using std::cout;
using std::cin;

void AccountHandler::ShowMenu() const
{
	cout << "=======�޴�=======\n";
	cout << "1. ���°���\n";
	cout << "2. �Ա�\n";
	cout << "3. ���\n";
	cout << "4. �������� ��ü ���\n";
	cout << "5. ����\n";
}

void AccountHandler::MakeAccount()
{
	int sel;
	cout << "[�������� ����]\n";
	cout << "1.���뿹�ݰ���\n";
	cout << "2.�ſ�ŷڰ���\n";
	cout << "����: ";
	cin >> sel;
	cout << '\n';

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}
void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[���뿹�ݰ��� ����]\n";
	cout << "����ID:"; cin >> id;
	cout << "�� ��:"; cin >> name;
	cout << "�Աݾ�:"; cin >> balance;
	cout << "������:"; cin >> interRate;
	cout << '\n';

	accArr[accNum++] = new NormalAccount(id, balance, name,interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[�ſ�ŷڰ��� ����]\n";
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���(1toA,2toB,3toC):"; cin >> creditLevel;
	cout << '\n';

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
	}
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "��    ��\n";
	cout << "���¹�ȣ �Է�: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�Ա� �Ϸ�\n";
			cout << "�Աݾ�:" << money << '\n';
			accArr[i]->GetBalance();
			return;
		}
		cout << "��ȿ���� ���� id�Դϴ�\n\n";
	}
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[��    ��]\n";
	cout << "���¹�ȣ �Է�: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ��� �����մϴ�\n";
				return;
			}
			cout << "��ݿϷ�\n";
			return;
		}
		cout << "��ȿ���� ���� id�Դϴ�\n\n";
	}
}

AccountHandler::AccountHandler():accNum(0)
{}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << '\n';
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}
