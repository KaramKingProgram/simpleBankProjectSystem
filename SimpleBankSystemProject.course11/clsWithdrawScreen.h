#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidateInput.h"
#include"clsScreen.h"

class clsWithdrawScreen :protected clsScreen
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

	static string _ReadAccountNumber() {
		return clsInputValidate::ReadString();
	}
public:

	static void WithdrawScreen() {
		HeaderScreen("Withdraw Screen");
		cout << "\nPlease Enter Account Number? ";
		string S = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(S)) {
			cout << "\nClient With [" << S << "] Does Not Exist.\nPlease Enter Anothe One? ";
			S = _ReadAccountNumber();

		}
		clsBankClient Client = clsBankClient::Find(S);
		_Print(Client);

		double Amount = 0;
		cout << "\nPlease Enter Withdraw Amount? ";
		Amount = clsInputValidate::ReadDoubleNumber("InValid Input, Please Enter Another One: ");



		cout << "\nAre You Sure Do You Want To Perform This Transaction? ";
		char Answer = 'y';
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			if (Client.Withdraw(Amount)) {
            cout << "\nAmount Withdraw Successfully.\n";
			cout << "\nNew Balance Is: " << Client.AccountBalance;
			 
			}
			else {
				cout << "\nCannot Withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to Withdraw Is: " << Amount;
				cout << "\nYour Balance Is: " << Client.AccountBalance;
			}
			
		}
		else {
			cout << "\nOperations was Cancelled.\n";
		}



	}

};

