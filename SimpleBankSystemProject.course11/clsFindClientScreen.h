#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidateInput.h"
#include"clsScreen.h"

class clsFindClientScreen:protected clsScreen
{
private:

	static void _Print(clsBankClient C)
	{
		cout << "Client Card:\n";
		cout << "---------------------\n";
		cout << "\nFirst Name  :" << C.FirstName;
		cout << "\nLast Name   :" << C.LastName;
		cout << "\nFull Name   :" << C.clsPerson::FullName();
		cout << "\nEmail       :" << C.Email;
		cout << "\nPhone Number:" << C.PhoneNumber;
		cout << "\nAcc. Number :" << C.AccountNumber();
		cout << "\nPin Code    :" << C.PinCode;
		cout << "\nAcc. Balance:" << C.AccountBalance;
		cout << "\n---------------------\n";


	}

public:
	static void FindClient() {
		if (!CheckAccessRigth(clsUser::enPermissions::pFindClient)) {
			return;
		}
		HeaderScreen("Find Client Screen");
		string AccountNumber;
		cout << "Please Enter Client Account Number: ";
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number Is Not Found, Enter another Choice: ";
			cin >> AccountNumber;
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (!Client.Is_Empty()) {

			cout << "\nClient Found :-)\n";
		}
		else {
			cout << "\nClient Was Not Found :-(\n";
		}
		_Print(Client);

	}
};

