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
		cout << "1~4 �޴� �Է�:"; cin >> choice;
		cout << '\n';

		switch (choice)
		{
		case MAKE:    //���� ����
			manager.MakeAccount();
			break;
		case DEPOSIT: //�Ա�
			manager.DepositMoney();
			break;
		case WITHDRAW://���
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸��� �Է�\n";
		}
	}
	return 0;
}