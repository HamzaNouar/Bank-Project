#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << "\033[32m" << Title << "\033[0m";
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << "\033[32m" << SubTitle << "\033[0m";
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		if (Chose == 1)
			cout << "\t\t\t\t\t\033[34mClient: \033[0m" << CurrentClient.AccountNumber() << endl;
		if (Chose == 2)
			cout << "\t\t\t\t\t\033[34mUser: \033[0m" << CurrentUser.UserName << endl;

		cout << "\t\t\t\t\t\033[34mDate: \033[0m" <<  clsDate::GetSystemDateTimeString() << endl;
		cout << "\t\t\t\t\t______________________________________\n";
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			//cout << "\t\t\t\t\t______________________________________";
			//cout << "\n\n\t\t\t\t\t  " << "\033[31m" << "Access Denied!Contact your Admin." << "\033[0m";
			//cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}

	}

	static string Tab(short Num)
	{
		string tab;

		for (short i = 1; i <= Num; i++)
		{
			tab += "\t";
		}

		return tab;
	}
};

