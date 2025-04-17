#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "Global.h"
#include <iomanip>
using namespace std;


class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer: ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		return AccountNumber;
	}


public:

	static void ShowTransferScreen()
	{
		
		_DrawScreenHeader("\t   Transfer Screen");

		clsBankClient ClientSource = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(ClientSource);
		
		clsBankClient ClientDestination = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(ClientDestination);

		float Amount;
		cout << "\nEnter Transfer Amount : ";
		Amount = clsInputValidate<float>::ReadNumberBetween(1, ClientSource.AccountBalance, "\nAmount Exceeds the available Balance, Enter another amount? ");
		
		cout << "\nAre you sure you want to perform this operation? ";


		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (ClientSource.Transfer(Amount, ClientDestination, CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully.\n";
				//_TransferLog(ClientSource, ClientDestination, Amount, CurrentUser.UserName);
			}
			else
			{
				cout << "\nTransfer Faild.\n";

			}
		}
			_PrintClient(ClientSource);
			_PrintClient(ClientDestination);

		

	}
};

