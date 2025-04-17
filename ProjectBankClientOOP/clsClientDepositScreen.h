#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsClientDepositScreen : protected clsScreen
{
private:

    


public:

	static void ShowClientDepositScreen()
	{
        _DrawScreenHeader("\t Client Deposit Screen");

        double Amount;
        cout << "\n" << Tab(4) << " Please enter deposit amount? ";
        Amount = clsInputValidate<double>::ReadNumberBetween(1, std::numeric_limits<double>::max(),"\nThe Amount is Wrong, Make Another Amount ? ");

        cout << "\n" << Tab(4) << " Are you sure you want to perform this transaction? Y/N? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            CurrentClient.Deposit(Amount);
            cout << "\n" << Tab(4) << " \033[33mAmount Deposited Successfully.\033[0m\n";
            cout << "\n" << Tab(4) << " New Balance Is: ";
            if (CurrentClient.AccountBalance < 50)
                cout << "\033[30m" << CurrentClient.AccountBalance << "$" << "\033[0m" << endl;
            else
                cout << "\033[32m" << CurrentClient.AccountBalance << "$" << "\033[0m" << endl;
        }
        else
        {
            cout << "\n" << Tab(4) << " Operation was cancelled.\n";
        }

    }
	

};

