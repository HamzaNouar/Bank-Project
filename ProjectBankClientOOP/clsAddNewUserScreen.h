#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate<string>::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate<string>::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate<string>::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate<string>::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate<string>::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {
        int Permisions = 0;
        char Answer;
        cout << "\nDo you want to give full acces? y/n? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give acces to: ";
        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permisions += clsUser::enPermissions::pListClients;

        cout << "\nAdd New Client ? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permisions += clsUser::enPermissions::pAddNewClient;

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permisions += clsUser::enPermissions::pDeleteClient;

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permisions += clsUser::enPermissions::pUpdateClients;

        cout << "\nFind Clients? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permisions += clsUser::enPermissions::pFindClient;

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permisions += clsUser::enPermissions::pTranactions;

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permisions += clsUser::enPermissions::pManageUsers;

        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permisions += clsUser::enPermissions::pLoginRegister;
        }

        cout << "\nShow Currency Exchange? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permisions += clsUser::enPermissions::pCurrencyExchange;


        return Permisions;
    }

public:

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t  Add New User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate<string>::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate<string>::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);


        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
    }

};
