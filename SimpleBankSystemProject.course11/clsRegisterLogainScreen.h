#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
class clsRegisterLogainScreen:protected clsScreen 
{
private:
	static void _PrintRegisterScreen(clsUser::LogainRegister User){
		cout << "\t\t\t| " << setw(25) << left << User.DateTime;
		cout << "| " << setw(30) << left << User.UserName;
		cout << "| " << setw(12) << left << User.Password;
		cout << "| " << setw(10) << left << User.Permissions;
	}
			

public:

	static void RegisterLogainScreen() {
		if (!CheckAccessRigth(clsUser::enPermissions::pRegisterList) ){
			return;
		}
		vector<clsUser::LogainRegister>vUser=clsUser::LoadUserRegisterDataFromFile();
		HeaderScreen("Logain Register List Screen", "(" + to_string(vUser.size()) + ") Record(s).");
		cout << setw(40) << "\n\t\t\t_______________________________________________________________________________________\n";
		cout << "\t\t\t| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(30) << "UserName";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(10) << "Permissions";

		cout << setw(40) << "\n\t\t\t_______________________________________________________________________________________\n";
		if (vUser.size() == 0) {

			
				cout << "\t\t\t\tNo Users Register Avilable In The System";
			
		}

		for (clsUser::LogainRegister &U : vUser) {

			_PrintRegisterScreen(U);
			cout << endl;
		}

		cout << setw(40) << "\n\t\t\t_______________________________________________________________________________________\n";

	}

};

