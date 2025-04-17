#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>

class clsUpdateCurrencyRateScreen :protected clsScreen
{
private:

    static float _ReadRate()
    {
        float Rate;
        cout << "\nEnter New Rate : ";
        Rate = clsInputValidate<float>::ReadNumber();
        return Rate;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

public:

    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode;
        cout << "\nPlease Enter CurrencyCode ? ";
        CurrencyCode = clsInputValidate<string>::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one ? ";
            CurrencyCode = clsInputValidate<string>::ReadString();
        }

        clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency1);


        cout << "\nAre you sure you want to update the Rate of this Currency y/n? ";

        char Answer = 'n';
        cin >> Answer;
        
        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";
            
            Currency1.UpdateRate(_ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";

            _PrintCurrency(Currency1);

        }
        
    }
};

