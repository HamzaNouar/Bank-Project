#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsString.h"
#include "clsDate.h"
#include "Global.h"
#include <vector>
#include <fstream>

class clsLoginRegister : protected clsScreen
{
private:

    static string _ConverLoginUserToLine(string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += clsDate::GetSystemDateTimeString() + Seperator;
        UserRecord += CurrentUser.UserName + Seperator;
        UserRecord += CurrentUser.Password + Seperator;
        UserRecord += to_string(CurrentUser.Permissions);

        return UserRecord;

    }


    static void _SaveUsersDataToFile()
    {

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);//overwrite

       // string DataLine;

        if (MyFile.is_open())
        {
                 
            MyFile << _ConverLoginUserToLine() << endl;

            MyFile.close();

        }

    }



public:


	static void AddLoginRegisterToFile()
	{
        _SaveUsersDataToFile();
	}
};

