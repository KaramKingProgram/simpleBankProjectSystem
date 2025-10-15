#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsValidateInput.h"
#include"clsScreen.h"
#include"clsUtill.h"
class clsTotalBalancesScreen:clsScreen
{
private:
	static void _PrintBalanceLineRecord(clsBankClient Client) {
		cout << "\t\t\t| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

public :
	static void TotalBalacne() {
		vector<clsBankClient>vClient = clsBankClient::LoadClientList();
		HeaderScreen("Total Balances Screen");
		cout << "\n\t\t\t\t\t   Client List (" << vClient.size() << ") Client (s)" << endl;
		cout <<setw(40) <<"\n\t\t\t_____________________________________________________________________________\n";
		cout << "\t\t\t| " << left << setw(15) << "Acc. Numbers";
		cout << "| " << left << setw(40) << "ClientName";
		cout << "| " << left << setw(12) << "Acc. Balance";
		cout << setw(40) << "\n\t\t\t_____________________________________________________________________________\n";

		float TotalBalances = clsBankClient::GetTotalBalances();

		if (vClient.size() == 0) {
			cout << "\t\t\t\tNo Clients Avilable In The System";
		}
		else

			for (clsBankClient& C : vClient) {
				_PrintBalanceLineRecord(C);
				cout << endl;

			}

		cout << setw(40) << "\n\t\t\t_____________________________________________________________________________\n";
		cout << "\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t[" << clsUtil::NumberToText(TotalBalances) << "]";



	}
};

