#include <iostream>
#include"AccountHandler.h"
#include"NormalAccount.h"
#include "HighCreditAccount.h"
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

void AccountHandler::MakeAccount()
{
	int sel;
	cout << "[계좌종류 선택]\n";
	cout << "1.보통예금계좌\n";
	cout << "2.신용신뢰계좌\n";
	cout << "선택: ";
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

	cout << "[보통예금계좌 개설]\n";
	cout << "계좌ID:"; cin >> id;
	cout << "이 름:"; cin >> name;
	cout << "입금액:"; cin >> balance;
	cout << "이자율:"; cin >> interRate;
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

	cout << "[신용신뢰계좌 개설]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << "신용등급(1toA,2toB,3toC):"; cin >> creditLevel;
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
