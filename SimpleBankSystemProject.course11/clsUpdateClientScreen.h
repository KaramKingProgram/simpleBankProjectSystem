#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidateInput.h"
#include"clsScreen.h"
class clsUpdateClientScreen:public clsScreen
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

	static 	void _ReadClientInfo(clsBankClient& Client) {

		cout << "Enter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone: ";
		Client.PhoneNumber = clsInputValidate::ReadString();

		cout << "Enter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter Acc. Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}



public:
	static void UpdateClientInfo() {
		if (!CheckAccessRigth(clsUser::enPermissions::pUpdateClient)) {
			return;
		}
		HeaderScreen("Update Client Screen");
		string AccountNumber;
		cout << "Please Enter Client Account Number: ";
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number Is Not Found, Enter another Choice: ";
			cin >> AccountNumber;
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		cout << "Update Client Info: \n-------------------\n";
		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\nAccount Ubdated Successfuly :-)" << endl;
			_Print(Client);
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\nError Account Was Not Saved Because It's Empty";
			break;
		default:
			break;
		}




	}

};

