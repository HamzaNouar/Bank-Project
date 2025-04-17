#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency, string Title = "\nCurrency Card:")
    {
        cout << Title;
        cout << "\n_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static clsCurrency _GetCurrency(string Message)
    {
        string CurrencyCode;
        cout << Message;
        CurrencyCode = clsInputValidate<string>::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one ? ";
            CurrencyCode = clsInputValidate<string>::ReadString();
        }

        clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);

        return Currency1;
    }

    static float _ReadAmount()
    {
        float Amount;
        cout << "\nEnter Amount to Exchange : ";
        Amount = clsInputValidate<float>::ReadNumber();

        return Amount;
    }

    static void _PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {
        float AmountToUSD = Currency1.ConvertToUSD(Amount);
        _PrintCurrency(Currency1, "\nConvert From : ");

        cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " <<
            AmountToUSD << " USD" << endl;

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConvert From USD to: ";

        _PrintCurrency(Currency1, "\n\nTo : ");
        float AmountToOtherCurrency = Currency1.ConvertToOtherCurrency(Amount,Currency2);

        cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " <<
            AmountToOtherCurrency << " " << Currency2.CurrencyCode() << endl;


    }
public:

    static void ShowCurrencyCalculatorScreen()
    {
        char Answer = 'y';

        while (Answer == 'Y' || Answer == 'y')
        {
        system("cls");
        _DrawScreenHeader("\tCurrency Calculator Screen");

        clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency 1 Code ? ");
        clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency 2 Code ? ");
        float Amount = _ReadAmount();

        _PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\ndo you want to perform another calculation y/n? ";
            cin >> Answer;

        } 
        

        
    }
};

