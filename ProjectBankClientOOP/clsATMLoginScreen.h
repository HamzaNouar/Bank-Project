#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsATMMainScreen.h"
#include <iomanip>

class clsATMLoginScreen : protected clsScreen
{
private:

    static bool _Login()
    {
        short Tries = 0;
        bool LoginFailed = false;
        string AccountNumber;
        string PinCode;

        do
        {
            if (LoginFailed)
            {
                Tries++;
                cout << "\n\t\t\t\t\tInvalid AccountNumber/PinCode!" << endl;
                cout << "\n\t\t\t\t\tYou have " << (3 - Tries) << " trial(s) to login.\n" << endl;
            }

            if (Tries == 3)
            {
                cout << "\n\t\t\t\t\tYou have locked after 3 faild trial(s)" << endl;
                return false;
            }

            cout << "\n\t\t\t\t\tEnter AccountNumber? ";
            cin >> AccountNumber;
            cout << "\n\t\t\t\t\tEnter PinCode? ";
            cin >> PinCode;

            CurrentClient = clsBankClient::Find(AccountNumber, PinCode);

            LoginFailed = CurrentClient.IsEmpty();

        } while (LoginFailed);

        //CurrentClient.RegisterLogIn();
        clsATMMainScreen::ShowATMMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        Chose = 1;
        _DrawScreenHeader("\tATM Login Screen");
        return _Login();
    }


};

