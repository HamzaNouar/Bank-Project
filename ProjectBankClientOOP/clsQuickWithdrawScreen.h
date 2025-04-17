#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsQuickWithdrawScreen : protected clsScreen
{
private:

    static short _ReadQuickWithdrawOption()
    {
        short Chose;
        cout << Tab(4) << "  Choose what do you want to do? [1 to 9]? ";
        Chose = clsInputValidate<short>::ReadNumberBetween(1, 9, "Enter Number Between 1 and 9 ? ");
        return Chose;
    }

    static short _getQuickWithdrawAmount(short QuickWithDrawOption)
    {
        switch (QuickWithDrawOption)
        {
        case 1:
            return 20;
        case 2:
            return 50;
        case 3:
            return 100;
        case 4:
            return 200;
        case 5:
            return 400;
        case 6:
            return 600;
        case 7:
            return 800;
            break;
        case 8:
            return 1000;
        default:
            return 0;
        }
    }

    static void _PerfromQuickWithdrawOption(short QuickWithDrawOption)
    {
        short Withdraw = _getQuickWithdrawAmount(QuickWithDrawOption);

        if (QuickWithDrawOption == 9)
        {
            return;
        }

        cout << "\n" << Tab(4) << "  Are you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {

            if (CurrentClient.Withdraw(Withdraw))
            {
                cout << "\n" << Tab(4) << "  Amount Withdrawed Successfully.\n";
                cout << "\n" << Tab(4) << "  New Balance Is: ";
                if (CurrentClient.AccountBalance < 50)
                    cout << "\033[30m" << CurrentClient.AccountBalance << "$" << "\033[0m" << endl;
                else
                    cout << "\033[31m" << CurrentClient.AccountBalance << "$" << "\033[0m" << endl;
            }
            else
            {
                cout << "\n" << Tab(4) << "  Cannot withdraw, Insuffecient Balance!\n";
                cout << "\n" << Tab(4) << "  Amout to withdraw is: " << Withdraw;
                cout << "\n" << Tab(4) << "  Your Balance is: " << CurrentClient.AccountBalance;
            }

        }
        else
        {
            cout << "\n" << Tab(4) << "  Operation was cancelled.\n";
        }

    }
        
    


public:
    static void ShowQuickWithrawScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Quick Withraw Screen");
        cout << Tab(4) << "   ===============================================\n";
        cout << Tab(5) << "\t  Quick Withraw\n";
        cout << Tab(4) << "   ===============================================\n";
        cout << Tab(4) << "\t  [1] 20$";
        cout << "\t[2] 50$\n";
        cout << Tab(4) << "\t  [3] 100$";
        cout << "\t[4] 200$\n";
        cout << Tab(4) << "\t  [5] 400$";
        cout << "\t[6] 600$\n";
        cout << Tab(4) << "\t  [7] 800$";
        cout << "\t[8] 1000$\n";
        cout << Tab(4) << "\t  [9] Exit\n";
        cout << Tab(4) << "   ===============================================\n";
        cout << Tab(4) << "  Your Balance is : ";
        cout <<  "\033[32m" << CurrentClient.AccountBalance << "$" << "\033[0m" << endl;
        _PerfromQuickWithdrawOption(_ReadQuickWithdrawOption());
    }
};

