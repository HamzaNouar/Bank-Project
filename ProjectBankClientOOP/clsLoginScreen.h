#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"


class clsLoginScreen : protected clsScreen
{
private:

    static bool _Login()
    {
        short Tries = 0;
        bool LoginFailed = false;
        string UserName;
        string Password;

        do
        {
            if (LoginFailed)
            {
                Tries++;
                cout << "\n\t\t\t\t\tInvalid UserName/Password!" << endl;
                cout << "\n\t\t\t\t\tYou have " << (3 - Tries) << " trial(s) to login.\n" << endl;
            }
                
            if (Tries == 3)
            {
                cout << "\n\t\t\t\t\tYou have locked after 3 faild trial(s)" << endl;
                return false;
            }

            cout << "\n\t\t\t\t\tEnter Username? ";
            cin >> UserName;
            cout << "\n\t\t\t\t\tEnter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);
        
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        Chose = 2;
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }
};

