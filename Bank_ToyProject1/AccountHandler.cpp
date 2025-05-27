#include <iostream>
#include"AccountHandler.h"
using std::cout;
using std::cin;

void AccountHandler::ShowMenu() const
{
	cout << "=======메뉴=======\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입금\n";
	cout << "3. 출금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 종료\n";
}

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]\n";
	cout << "계좌ID:"; cin >> id;
	cout << "이 름:"; cin >> name;
	cout << "입금액:"; cin >> balance;
	cout << '\n';

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "입    금\n";
	cout << "계좌번호 입력: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금 완료\n";
			cout << "입금액:" << money << '\n';
			accArr[i]->GetBalance();
			return;
		}
		cout << "유효하지 않은 id입니다\n\n";
	}
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출    금]\n";
	cout << "계좌번호 입력: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액이 부족합니다\n";
				return;
			}
			cout << "출금완료\n";
			return;
		}
		cout << "유효하지 않은 id입니다\n\n";
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
