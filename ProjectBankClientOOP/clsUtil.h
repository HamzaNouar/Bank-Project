#pragma once
#include<cstdlib>
#include <iostream>
#include "clsDate.h"

using namespace std;


class clsUtil
{
public:
    static int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    enum enTypeCharacter { SmCharacter = 1, CapCharacter = 2, Digits = 3, SpCharacter = 4, MixChars = 5 };

    static char GetRandomCharacter(enTypeCharacter TypeCharacter)
    {
        if (TypeCharacter == MixChars)
            TypeCharacter = (enTypeCharacter)RandomNumber(1, 3);
        //Function to generate a random number
        switch (TypeCharacter)
        {
        case enTypeCharacter::SmCharacter:
            return (char)RandomNumber(97, 122);
        case enTypeCharacter::CapCharacter:
            return (char)RandomNumber(65, 90);
        case enTypeCharacter::SpCharacter:
            return (char)RandomNumber(33, 47);
        case enTypeCharacter::Digits:
            return (char)RandomNumber(48, 57);

        }

    }

    static string GenerateWord(enTypeCharacter charType, short Length)
    {

        string word = "";

        for (int i = 1; i <= Length; i++)
        {
            word = word + GetRandomCharacter(charType);
        }

        return word;
    }

    static string GenerateKey(enTypeCharacter charType = CapCharacter)
    {
        string key = "";

        key = key + GenerateWord(charType, 4) + "-";
        key = key + GenerateWord(charType, 4) + "-";
        key = key + GenerateWord(charType, 4) + "-";
        key = key + GenerateWord(charType, 4);

        return key;

    }

    static void GenerateKeys(int NumberOfKeys, enTypeCharacter charType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "key[" << i << "]: " << GenerateKey(charType) << endl;
        }

    }

    static void Swap(int& A, int& B)
    {
        int swap;
        swap = A;
        A = B;
        B = swap;
    }

    static void Swap(double& A, double& B)
    {
        double swap;
        swap = A;
        A = B;
        B = swap;
    }

    static void Swap(bool& A, bool& B)
    {
        bool swap;
        swap = A;
        A = B;
        B = swap;
    }

    static void Swap(char& A, char& B)
    {
        char swap;
        swap = A;
        A = B;
        B = swap;
    }

    static void Swap(string& A, string& B)
    {
        string swap;
        swap = A;
        A = B;
        B = swap;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDate(A, B);
    }

    static void ShuffleArray(int Arr[100], int LengthArr)
    {
        for (int i = 0; i <= LengthArr - 1; i++)
        {

            Swap(Arr[RandomNumber(1, LengthArr) - 1], Arr[RandomNumber(1, LengthArr) - 1]);


        }
        cout << endl;


    }

    static void ShuffleArray(string Arr[100], int LengthArr)
    {
        for (int i = 0; i <= LengthArr - 1; i++)
        {

            Swap(Arr[RandomNumber(1, LengthArr) - 1], Arr[RandomNumber(1, LengthArr) - 1]);


        }
        cout << endl;


    }

    static void FillArrayWithRandomNumbers(int Arr[100], int LengthArr, short From, short To)
    {
        for (int i = 0; i <= LengthArr - 1; i++)
        {
            Arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string Arr[100], int LengthArr, enTypeCharacter charType, short WordLength)
    {
        for (int i = 0; i <= LengthArr - 1; i++)
        {
            Arr[i] = GenerateWord(charType, WordLength);
        }
    }

    static void FillArrayWithRandomKeys(string Arr[100], int LengthArr, enTypeCharacter charType)
    {
        for (int i = 0; i <= LengthArr - 1; i++)
        {
            Arr[i] = GenerateKey(charType);
        }
    }

    static string Tabs(short Num)
    {
        string tab = "";

        for (short i = 1; i <= Num; i++)
        {
            tab += "\t";
        }

        return tab;
    }

    static string EncryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }

        return Text;
    }

    static string NumberToText(int Number)
    {
        string smallNumbers[] = { "zero", "one", "two", "three", "four", "five","six", "seven", "eight", "nine", "ten","eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen" };
        string Decades[] = { "", "", "twenty", "thirty", "forty","fifty", "sixty", "seventy", "eighty", "ninety" };


        if (Number == 0)
        {
            return "";
        }
        if (Number >= 1 && Number <= 19)
        {
            return smallNumbers[Number] + " ";
        }
        else if (Number >= 20 && Number <= 99)
        {
            return Decades[Number / 10] + " " + NumberToText(Number % 10);
        }
        else if (Number >= 100 && Number <= 199)
        {
            return  "One Handred " + NumberToText(Number % 100);
        }
        else if (Number >= 200 && Number <= 999)
        {
            return  NumberToText(Number / 100) + "Handredes " + NumberToText(Number % 100);
        }
        else if (Number >= 1000 && Number <= 1999)
        {
            return  "One thousand " + NumberToText(Number % 1000);
        }
        else if (Number >= 2000 && Number <= 999999)
        {
            return  NumberToText(Number / 1000) + "thousands " + NumberToText(Number % 1000);
        }
        else if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }
        else if (Number >= 2000000 && Number <= 999999999)
        {
            return  NumberToText(Number / 1000000) + "millions " + NumberToText(Number % 1000000);
        }
        else if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return  NumberToText(Number / 1000000000) + "billions " + NumberToText(Number % 1000000000);
        }

    }
};

