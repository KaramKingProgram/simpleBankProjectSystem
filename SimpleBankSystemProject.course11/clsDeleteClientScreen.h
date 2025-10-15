#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidateInput.h"
#include"clsScreen.h"

class clsDeleteClientScreen:protected clsScreen
{
private:

static	void Print(clsBankClient C) {
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
	static void DeleteClient() {
		if (!CheckAccessRigth(clsUser::enPermissions::pDeleteClient)) {
			return;
		}
	    HeaderScreen("Delete Client Screen");
		cout << "\nPlease Enter AccountNumber: ";
		string AccountNumber = clsInputValidate::ReadString();
	
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Found, Enter another Choice: ";
			cin >> AccountNumber;
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Print(Client);
		cout << "\nAre You sure Do you Want To Delete Client?";
		char c;
		cin >> c;
		while (tolower(c) == 'y') {
			if (Client.Delete()) {
				cout << "\nClient Deleted Successfuly.\n" << endl;
				Print(Client);
				break;
			}
			else {

				break;
			}




		}




	}


};

