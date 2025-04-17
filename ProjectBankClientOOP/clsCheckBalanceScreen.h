#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsCheckBalanceScreen : protected clsScreen
{


public:

	static void ShowCheckBalanceScreen()
	{
		_DrawScreenHeader("\tCheck Balance Screen");

		cout << "\n" << Tab(5) << "Your Balance Is: ";
		if (CurrentClient.AccountBalance < 50)
			cout << "\033[30m" << CurrentClient.AccountBalance << "$" << "\033[0m" << endl;
		else
			cout << "\033[32m" << CurrentClient.AccountBalance << "$" << "\033[0m" << endl;
	}


};

