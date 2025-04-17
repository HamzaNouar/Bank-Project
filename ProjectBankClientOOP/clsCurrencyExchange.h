#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsCurrencyExchange :protected clsScreen
{
private:

    enum enCurrencyExchangeMenueOptions {
        eListCurrency = 1, eFindCurrency = 2, eUpdateCurrency = 3,
        eCurrencyCalc = 4, eCurrencyMainMenue = 6
    };
    static short ReadCurrencyExchangeMenueOptions()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowCurrencyExchangeScreen();
    }

    static void _ShowListCurrencysScreen()
    {
        cout << "\nList Currencys Screen Will Be Here.\n";
    }

    static void _ShowFindCurrencysScreen()
    {
        cout << "\nFind Currencys Screen Will Be Here.\n";
    }

    static void _ShowUpdateRateScreen()
    {
        cout << "\nUpdate Rate Screen Will Be Here.\n";
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        cout << "\nCurrency Calculator Screen Will Be Here.\n";
    }

    static void _PerformCurrencyExchangeMenueOptions(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOptions)
    {

        switch (CurrencyExchangeMenueOptions)
        {
        case enCurrencyExchangeMenueOptions::eListCurrency:
        {
            system("cls");
            _ShowListCurrencysScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enCurrencyExchangeMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencysScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enCurrencyExchangeMenueOptions::eUpdateCurrency:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enCurrencyExchangeMenueOptions::eCurrencyCalc:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enCurrencyExchangeMenueOptions::eCurrencyMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }



public:

    static void ShowCurrencyExchangeScreen()
    {
        /*if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }*/

        system("cls");
        _DrawScreenHeader("   Currency Exchange Menue Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformCurrencyExchangeMenueOptions((enCurrencyExchangeMenueOptions)ReadCurrencyExchangeMenueOptions());
    }
};

