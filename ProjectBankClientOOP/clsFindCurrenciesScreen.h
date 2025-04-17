#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>

class clsFindCurrenciesScreen :protected clsScreen
{
private:


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

    static void _ShowResults(clsCurrency Currency)
    {
        

        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }

        
    }

public:

    static void ShowFindCurrenciesScreen()
    {

        _DrawScreenHeader("\tFind Currency Screen");
        
        short Answer;
        cout << "\nFind By: [1] Code or [2] Country ? ";
        Answer = clsInputValidate<short>::ReadNumberBetween(1, 2, "\nEnter Number Between 1 & 2 ? ");

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter CurrencyCode ? ";
            CurrencyCode = clsInputValidate<string>::ReadString();
            clsCurrency Currency1 = Currency1.FindByCode(CurrencyCode);
            _ShowResults(Currency1);
        }
        else
        {
            string CurrencyCountry;
            cout << "\nPlease Enter CurrencyCountry ? ";
            CurrencyCountry = clsInputValidate<string>::ReadString();
            clsCurrency Currency1 = Currency1.FindByCountry(CurrencyCountry);
            _ShowResults(Currency1);
        }

    }
};

