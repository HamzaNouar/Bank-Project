#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsNormalWithdrawScreen : protected clsScreen
{

public:

	static void ShowNormalWithdrawScreen()
	{
        
        _DrawScreenHeader("\t Normal Withdraw Screen");

        double Amount;
        cout << "\n" << Tab(4) << " Please enter withdraw amount? ";
        Amount = clsInputValidate<double>::ReadNumberBetween(1,CurrentClient.AccountBalance,"\n\t\t\tThe Amount Exceeds Your balance, Make Another Amount ? ");


        cout << "\n" << Tab(4) << "  Are you sure you want to perform this transaction? y/n ? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {

            if (CurrentClient.Withdraw(Amount))
            {
                cout << "\n" << Tab(4) << "  Amount Withdrawed Successfully.\n";
                cout << "\n" << Tab(4) << "  New Balance Is: ";
                if (CurrentClient.AccountBalance < 50)
                    cout << "\033[30m" << CurrentClient.AccountBalance << "$" << "\033[0m" << endl;
                else
                    cout << "\033[32m" << CurrentClient.AccountBalance << "$" << "\033[0m" << endl;
            }
            else
            {
                cout << "\n" << Tab(4) << "  Cannot withdraw, Insuffecient Balance!\n";
                cout << "\n" << Tab(4) << "  Amout to withdraw is: " << Amount;
                cout << "\n" << Tab(4) << "  Your Balance is: " << CurrentClient.AccountBalance;
            }

        }
        else
        {
            cout << "\n" << Tab(4) << "  Operation was cancelled.\n";
        }
	}
};

