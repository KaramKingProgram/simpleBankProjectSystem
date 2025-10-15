#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"


class clsClientListScreen:protected clsScreen
{

public:
	static void PrintClientLineRecord(clsBankClient Client) {
	cout <<"| " << setw(15) << left <<Client.AccountNumber();
	cout <<"| " << setw(25) << left <<Client.FullName();
	cout <<"| " << setw(12) << left <<Client.PhoneNumber;
	cout <<"| " << setw(30) << left <<Client.Email;
	cout <<"| " << setw(10) << left <<Client.PinCode;
	cout <<"| " << setw(12) << left <<Client.AccountBalance;

}

	static void ClientsList() {
		if (!CheckAccessRigth(clsUser::enPermissions::pListClients) ){
			return;
		}

		vector<clsBankClient>vClient = clsBankClient::LoadClientList();
		string Size = to_string(vClient.size());
		clsScreen::HeaderScreen("Client List Screen","("+Size+") Client (s)");
		
		cout << "\n________________________________________________________________________________________________________________________\n";
		cout << "| " << left << setw(15) << "Acc. Numbers";
		cout << "| " << left << setw(25) << "ClientName";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(30) << "Email";
		cout << "| " << left << setw(10) << "PinCode"; 
		cout << "| " << left << setw(12) << "Acc. Balance";

		cout << "\n________________________________________________________________________________________________________________________\n";
		if (vClient.size() == 0) {
			cout << "\t\t\t\tNo Clients Avilable In The System";
		}
		else

			for (clsBankClient& C : vClient) {
				PrintClientLineRecord(C);
				cout << endl;

			}

		cout << endl;
		cout << "\n________________________________________________________________________________________________________________________\n";

	}

};

