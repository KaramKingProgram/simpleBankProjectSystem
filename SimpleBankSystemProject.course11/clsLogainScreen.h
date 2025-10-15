#pragma once
#include<iostream>
#include"clsScreen.h"
#include"Global.h"
#include"clsMainScreen.h"


clsUser CurrentUser = clsUser::Find("", "");
class clsLogainScreen:protected clsScreen
{
private:
	static bool _Logain() {
		bool UserFaild = false;
		string UserName, Password;
		short Attemp = 0;
		do {
			if (UserFaild) {
				cout << "\nInvalid UserName/Password!\n";
				Attemp++;
				cout << "You have " << (3 - Attemp) << " Trails To Logain!!\n";
				if (Attemp == 3) {
					cout << "\n\nYou Are Locked After 3 Faild Trials" << endl;
					return false;
				}


			}
			cout << "\nEnter User Name: ";
			cin >> UserName;
			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			UserFaild = CurrentUser.IsEmpty();


		} while (UserFaild);

		CurrentUser.SaveRegistorDataOnFile();
		clsMainScreen::ShowMainMenueScreen();

		return true;
	}
public :
	static bool LogainScreen() {
		HeaderScreen("\tLogain");
		return _Logain();

	}

};

