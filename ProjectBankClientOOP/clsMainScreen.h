#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include "Global.h"
#include <iomanip>
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenueOption(vector<short> vUserOption)
    {
        string Option = to_string(vUserOption.size());
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to " + Option + "]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, vUserOption.size(), "Enter Number between 1 to " + Option + " ? ");
        return vUserOption[Choice - 1];
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        //cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        //cout << "\nEnd Screen Will be here...\n";
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeMainScreen()
    {
        //cout << "\nEnd Screen Will be here...\n";
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }

    static void _Logout()
    {
        //cout << "\nEnd Screen Will be here...\n";
        CurrentUser = clsUser::Find("", "");
        Chose = 0;
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeMainScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            //system("cls");
            //_ShowEndScreen();
            _Logout();

            break;
        }

    }



public:


    static void ShowMainMenue()
    {
        vector <short> vOption;
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
        short NumberOption = 1;
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << "\033[32m" << left << "" << "\t\t     Main Menue\033[0m\n";
        cout << setw(37) << left << "" << "===========================================\n";
        if (CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            cout << setw(37) << "\033[35m" << right << "\t[" << NumberOption << "]" << " Show Client List.\033[0m\n";
            NumberOption++;
            vOption.push_back(1);
        }
        if (CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            cout << setw(37) << "\033[35m"<< "\t[" << NumberOption << "] Add New Client.\033[0m\n";
            NumberOption++;
            vOption.push_back(2);
        }
        if (CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            cout << setw(37) << "\033[35m" << "\t[" << NumberOption << "] Delete Client.\033[0m\n";
            NumberOption++;
            vOption.push_back(3);
        }
        if (CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            cout << setw(37) << "\033[35m" << "\t[" << NumberOption << "] Update Client Info.\033[0m\n";
            NumberOption++;
            vOption.push_back(4);
        }
        if (CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            cout << setw(37) << "\033[35m" << "\t[" << NumberOption << "] Find Client.\033[0m\n";
            NumberOption++;
            vOption.push_back(5);
        }
        if (CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            cout << setw(37) << "\033[35m" << "\t[" << NumberOption << "] Transactions.\033[0m\n";
            NumberOption++;
            vOption.push_back(6);
        }
        if (CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            cout << setw(37) << "\033[35m" << "\t[" << NumberOption << "] Manage Users.\033[0m\n";
            NumberOption++;
            vOption.push_back(7);
        }
        if (CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            cout << setw(37) << "\033[35m" << "\t[" << NumberOption << "] Login Register.\033[0m\n";
            NumberOption++;
            vOption.push_back(8);
        }
        if (CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            cout << setw(37) << "\033[35m" << "\t[" << NumberOption << "] Currency Exchange.\033[0m\n";
            NumberOption++;
            vOption.push_back(9);
        }

        cout << setw(37) << "\033[31m" << "\t[" << NumberOption << "] Logout.\033[0m\n";
        vOption.push_back(10);
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption(vOption));
    }

};

