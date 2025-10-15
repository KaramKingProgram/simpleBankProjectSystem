#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsValidateInput.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsRegisterLogainScreen.h"

using namespace std;
class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions { ShowClientList = 1, AddNewClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Transactions = 6, ManageUsers = 7, Logout = 8,Logain=9,Exit=10 };
	static void _ShowClientListScreen() {

		clsClientListScreen::ClientsList();
	}

	static void _AddNewClientScreen() {
		clsAddNewClientScreen::AddNewClient();
	}
	
	static void _DeleteClientScreen() {
		clsDeleteClientScreen::DeleteClient();

	}

	static void _UpdateClientScreen() {
	
		clsUpdateClientScreen::UpdateClientInfo();
	}

	static void _FindClientScreen() {

		clsFindClientScreen::FindClient();

	}

	static void _TransactionsMenue() {
		clsTransactionsScreen::ShowTransactionsMenue();
		_GoBackToMainMenue();
	}

	static void _ManageUsersMenue() {
		clsManageUsersScreen::ShowManageUsersMenue();
		
	}

	static void _LogainRegisterScreen() {
		clsRegisterLogainScreen::RegisterLogainScreen();
	}

	static void _LogoutScreen() {
		CurrentUser = clsUser::Find("", "");
		
	}

    static void _ExitScreen() {
		
		cout <<   "\t\t+++++++++++++++++++++++++++++++++"<<endl;
		cout <<  "\t\t\tEnd Program :-)"<<endl;
		cout <<   "\t\t+++++++++++++++++++++++++++++++++"<<endl;
        exit(0);
	}

	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenueScreen();
	}

	static short _ReadUserOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
		return Choice;
	}
		
	static	void _PerformMainMenueOption(enMainMenueOptions Option) {
		switch (Option)
		{
		case enMainMenueOptions::ShowClientList:
		{
			system("cls");
			_ShowClientListScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::AddNewClient:
			system("cls");
			_AddNewClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::DeleteClient:
			system("cls");
			_DeleteClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::UpdateClient:
			system("cls");
			_UpdateClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::FindClient:
			system("cls");
			_FindClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::Transactions:
			system("cls");
			_TransactionsMenue();
			break;

		case enMainMenueOptions::ManageUsers:
			system("cls");
			_ManageUsersMenue();
			_GoBackToMainMenue();
				break;

		case enMainMenueOptions::Logout:
			system("cls");
			_LogoutScreen();
			break;
		case enMainMenueOptions::Logain:
			system("cls");
			_LogainRegisterScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::Exit:
			system("cls");
			_ExitScreen();
			
			
		}



	}

public:


static	void ShowMainMenueScreen() {

		system("cls");
		HeaderScreen("Good Morning","Main Menue:");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "[1] Show Client List" << endl;
		cout << setw(37) << left << "" << "[2] Add New Client" << endl;
		cout << setw(37) << left << "" << "[3] Delete Client" << endl;
		cout << setw(37) << left << "" << "[4] Update Client" << endl;
		cout << setw(37) << left << "" << "[5] Find Client" << endl;
		cout << setw(37) << left << "" << "[6] Transactions" << endl;
		cout << setw(37) << left << "" << "[7] Manage Users" << endl;
		cout << setw(37) << left << "" << "[8] Logout" << endl;
		cout << setw(37) << left << "" << "[9] Login Register" << endl;
		cout << setw(37) << left << "" << "[10] Exit" << endl;
		cout << setw(37) << left << "" << "===========================================\n";
		
		_PerformMainMenueOption((enMainMenueOptions) _ReadUserOption());
	}




};

