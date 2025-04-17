#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsWithdrawScreen.h"
#include "clsDepositScreen.h"
#include "clsQuickWithdrawScreen.h"
#include "clsNormalWithdrawScreen.h"
#include "clsClientDepositScreen.h"
#include "clsCheckBalanceScreen.h"
#include <iomanip>

class clsATMMainScreen : protected clsScreen
{
private:
    enum enATMMenueOptions {
        eQuickWithraw = 1, eNormalWithraw, eDeposit, eCheckBalance, eLogout };

    static short _ReadATMMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number between 1 to 8? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\n\tPress any key to go back to ATM Menue...\n";

        system("pause>0");
        ShowATMMainMenue();
    }

    static void _ShowQuickWithdrawScreen()
    {
        //cout << "\n QuickWithdrawScreen Will be here...\n";
        clsQuickWithdrawScreen::ShowQuickWithrawScreen();
    }

    static void _ShowNormalWithdrawScreen()
    {
        //cout << "\n NormalWithdrawScreen Will be here...\n";
        clsNormalWithdrawScreen::ShowNormalWithdrawScreen();
    }

    static void _ShowDepositScreen()
    {
        //cout << "\n DepositScreen Will be here...\n";
        clsClientDepositScreen::ShowClientDepositScreen();
    }

    static void _ShowCheckBalanceScreen()
    {
        //cout << "\n CheckBalanceScreen Will be here...\n";
        clsCheckBalanceScreen::ShowCheckBalanceScreen();
    }

    static void _Logout()
    {
        //cout << "\nEnd Screen Will be here...\n";
        CurrentClient = clsBankClient::Find("", "");
        Chose = 0;
    }

    static void _PerfromATMMenueOption(enATMMenueOptions ATMMenueOption)
    {
        switch (ATMMenueOption)
        {
        case enATMMenueOptions::eQuickWithraw:
        {
            system("cls");
            _ShowQuickWithdrawScreen();
            _GoBackToMainMenue();
            break;
        }
        case enATMMenueOptions::eNormalWithraw:
            system("cls");
            _ShowNormalWithdrawScreen();
            _GoBackToMainMenue();
            break;

        case enATMMenueOptions::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToMainMenue();
            break;

        case enATMMenueOptions::eCheckBalance:
            system("cls");
            _ShowCheckBalanceScreen();
            _GoBackToMainMenue();
            break;

        case enATMMenueOptions::eLogout:
            //system("cls");
            _Logout();
            //_GoBackToMainMenue();
            break;
        }

    }



public:


    static void ShowATMMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\tATM Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tATM Main Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Quick Withraw.\n";
        cout << setw(37) << left << "" << "\t[2] Normal Withraw.\n";
        cout << setw(37) << left << "" << "\t[3] Deposit.\n";
        cout << setw(37) << left << "" << "\t[4] Check Balance.\n";
        cout << setw(37) << left << "" << "\t[5] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromATMMenueOption((enATMMenueOptions)_ReadATMMenueOption());
    }
};

