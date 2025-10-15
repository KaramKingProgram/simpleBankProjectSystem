#pragma once
#include<iostream>
#include"clsDate.h"
#include "Global.h"
#include"clsUser.h"
class clsScreen
{


protected:
	static void HeaderScreen(string HeaderText,string SubText="") {

		cout  << "\t\t\t\t  *************************************************\n";
		cout  <<"\n\t\t\t\t\t\t"<< HeaderText;
		if (SubText != "") {
			cout << "\n\t\t\t\t\t\t\t" << SubText;
		}cout << "\n\t\t\t\t  Date: "<<clsDate::ToStringDate();
		
		cout << "\n\t\t\t\t  Time: "<<clsDate::ToStringTime();
		
		
		
		cout << "\n\n\t\t\t\t  *************************************************\n\n";
		cout << "\t\t\t\t  User Name: " << CurrentUser.UserName<<endl;
	}
	static bool CheckAccessRigth(clsUser::enPermissions Permission) {
		if (!CurrentUser.CheckAccsessPermissions(Permission)) {
			cout << "\t\t\t\t  *************************************************\n";

			cout << "\n\t\t\t\t\t\t" << "Access Denied! Contact Your Admin.";

			cout << "\n\n\t\t\t\t  *************************************************\n\n";
			return false;
		}
		else
			return true;


	}

};

