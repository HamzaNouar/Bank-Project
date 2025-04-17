#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsATMLoginScreen.h"
#include "clsLoginScreen.h"
using namespace std;

class clsChooseLoginScreen : protected clsScreen
{
private:

    static short _ReadMenuOption()
    {

        cout << "\n\t\t\t\t    Choose what do you want to do? [1 to 2]? ";
        short Chose = clsInputValidate<short>::ReadNumberBetween(1, 2, "\nEnter Number Between 1 and 2 ? ");
        return Chose;
    }

    static void BackToMainScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Chose Menue...\n";
        system("pause>0");
        ShowChooseLoginScreen();
        return;
    }
    static void _PerfromMenueOption(short MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case 1:
        {
            //system("cls");
            clsATMLoginScreen::ShowLoginScreen();
            BackToMainScreen();
            break;
        }
        case 2:
        {
            //system("cls");
            clsLoginScreen::ShowLoginScreen();
            BackToMainScreen();
            break;
        }

        }
    }

public:

    static void ShowChooseLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\tChoose Login Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << "\033[32m" << left << "" << "\t\t     Main Menue\033[0m\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << "\033[35m" << left << "" << "\t[1] ATM Bank.\033[0m\n";
        cout << setw(37) << "\033[35m" << left << "" << "\t[2] Bank System.\033[0m\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromMenueOption(_ReadMenuOption());

    }
};