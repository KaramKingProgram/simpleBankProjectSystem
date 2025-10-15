#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsValidateInput.h"
class clsAddNewUserScreen:protected clsScreen

{
private:
	static void _ReadUserInfo(clsUser &User) {
		string S;
		cout << "\nEnter  First Name: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		User.PhoneNumber = clsInputValidate::ReadString();
		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permission: ";
		User.Permissions = _ReadPermissionsToSet();


	}


	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.PhoneNumber;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

	static int _ReadPermissionsToSet() {
		int Permission = 0;
		cout << "\nDo You Want to Give Full Access? y/n? ";
		char s;
		cin >> s;
		if (tolower(s) == 'y') {
			
			return -1;
		}
	
		cout << "\nDo You Want To Give Access To : \n";

		cout << "\nShow Client List? y/n? ";
		cin >> s;
		if (tolower(s) == 'y') {
			Permission += clsUser::enPermissions::pListClients;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> s;
		if (tolower(s) == 'y') {
			Permission += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> s;
		if (tolower(s) == 'y') {
			Permission += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> s;
		if (tolower(s) == 'y') {
			Permission += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nFind Client? y/n? ";
		cin >> s;
		if (tolower(s) == 'y') {
			Permission += clsUser::enPermissions::pFindClient;
		}
		
		cout << "\nTransactions? y/n? ";
		cin >> s;
		if (tolower(s) == 'y') {
			Permission += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage User? y/n? ";
		cin >> s;
		if (tolower(s) == 'y') {
			Permission += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nRegister User List? y/n? ";
		cin >> s;
		if (tolower(s) == 'y') {
			Permission += clsUser::enPermissions::pRegisterList;
		}

		

		return Permission;
	}


public:
	static void AddNewUserScreen() {

		HeaderScreen("\t  Add New User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName Is Already Used, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case  clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Addeded Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError User was not saved because it's Empty";
			break;

		}
		case clsUser::enSaveResults::svFaildUserExists:
		{
			cout << "\nError User was not saved because UserName is used!\n";
			break;

		}
		}


	}
};

