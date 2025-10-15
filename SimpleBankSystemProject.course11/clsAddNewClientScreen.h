#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsValidateInput.h"


class clsAddNewClientScreen:protected clsScreen
{
private:
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

static	void _PrintClientInfo(clsBankClient Client)  {
		
			cout << "Client Card:\n";
			cout << "---------------------\n";
			cout << "\nFirst Name  :" <<Client.FirstName;
			cout << "\nLast Name   :" <<Client.LastName;
			cout << "\nFull Name   :" <<Client.clsPerson::FullName();
			cout << "\nEmail       :" <<Client.Email;
			cout << "\nPhone Number:" <<Client.PhoneNumber;
			cout << "\nAcc. Number :" <<Client.AccountNumber();
			cout << "\nPin Code    :" <<Client.PinCode;
			cout << "\nAcc. Balance:" <<Client.AccountBalance;
			cout << "\n---------------------\n";


		

	}
public:
	static void AddNewClient() {
		if (!CheckAccessRigth(clsUser::enPermissions::pAddNewClient)) {
			return;
		}
		string AccountNumber = "";

		HeaderScreen("Add New Client Screen");
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number Is Already Used, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError account was not Saved because it's Empty";
			break;
		case clsBankClient::svSucceeded:
			cout << "\nAccount Addeded Successfuly :-)\n";
			_PrintClientInfo(NewClient);
			break;
		case clsBankClient::svFaildAccountNumberExists:
			cout << "\nError account was not saved because account number is used!\n";
			break;
		default:
			break;
		}

	}

};

