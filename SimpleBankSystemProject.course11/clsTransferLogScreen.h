#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
class clsTransferLogScreen:protected clsScreen
{
	static void _PrintRegistorTransfer(clsBankClient::stTransfer C) {
		cout << "\t\t\t| " << left << setw(25) << C.DateTime;
		cout << "| " << left << setw(10) << C.AccountNumber1;
		cout << "| " << left << setw(10) << C.AccountNumber2;
		cout << "| " << left << setw(10) << C.Amount;
		cout << "| " << left << setw(10) << C.Balance1;
		cout << "| " << left << setw(10) << C.Balance2;
		cout << "| " << left << setw(12) << C.UserName;
	}


		


public:
	static void RegisterLogainScreen() {
		
		vector<clsBankClient::stTransfer>vClient = clsBankClient::LoadRegistorTransDataFromFile();
		HeaderScreen("Transfer Log List Screen", "(" + to_string(vClient.size()) + ") Record(s).");
		cout << setw(40) << "\n\t\t\t_________________________________________________________________________________________________\n";
		cout << "\t\t\t| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acc";
		cout << "| " << left << setw(10) << "d.Acc";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";

		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(12) << "User";

		cout << setw(40) << "\t\t\t_________________________________________________________________________________________________\n";
		if (vClient.size() == 0) {


			cout << "\t\t\t\tNo CLients Transfer Register Avilable In The System";

		}

		for (clsBankClient::stTransfer& C : vClient) {
			_PrintRegistorTransfer(C);
			
		}

		cout << setw(40) << "\n\t\t\t_________________________________________________________________________________________________\n";

	}


};

