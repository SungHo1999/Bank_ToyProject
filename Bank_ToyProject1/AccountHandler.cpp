#include <iostream>
#include"AccountHandler.h"
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

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]\n";
	cout << "����ID:"; cin >> id;
	cout << "�� ��:"; cin >> name;
	cout << "�Աݾ�:"; cin >> balance;
	cout << '\n';

	accArr[accNum++] = new Account(id, balance, name);
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
