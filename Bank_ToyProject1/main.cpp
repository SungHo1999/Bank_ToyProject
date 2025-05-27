#include<iostream>
#include<cstring>
#include "Account.h"
#include "AccountHandler.h"
using std::cout;
using std::cin;
int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "1~4 메뉴 입력:"; cin >> choice;
		cout << '\n';

		switch (choice)
		{
		case MAKE:    //계좌 개설
			manager.MakeAccount();
			break;
		case DEPOSIT: //입금
			manager.DepositMoney();
			break;
		case WITHDRAW://출금
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "잘못된 입력\n";
		}
	}
	return 0;
}