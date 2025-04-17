#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsBankClient.h"

clsUser CurrentUser = clsUser::Find("", "");
clsBankClient CurrentClient = clsBankClient::Find("", "");
short Chose = 0;

