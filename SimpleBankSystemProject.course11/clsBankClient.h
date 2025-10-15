#pragma once
#include<iostream>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "clsString.h"
#include"clsPerson.h"
#include"Global.h"
using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum EnMode {EmptyMode=0,UbdateMode=1,AddNewMode=2};
	EnMode _Mode;

	string _PinCode;
	string _AccountNumber;
	float _AccountBalance;
	bool MarkToDelete = false;
	
	
	static clsBankClient _ConvertLinetoClientObject(string Line, string Seprator="#//#") {


		vector<string> vClient = clsString::Split(Line, Seprator);
		return clsBankClient(EnMode::UbdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));


	};

	static  string _ConvertClientsTransferToLine(clsBankClient SourceClient, clsBankClient DesClient,float Amount, string Sep = "#//#") {
		string Line = "";
		Line += clsDate::GetDateAndTime() + Sep;
		Line += SourceClient.AccountNumber() + Sep;
		Line += DesClient.AccountNumber() + Sep;
		Line += to_string(Amount) + Sep;
		Line += to_string(SourceClient.AccountBalance) + Sep;
		Line += to_string(DesClient.AccountBalance) + Sep;
		Line += CurrentUser.UserName;
		return Line;

	}
	

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(EnMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Sep = "#//#") {
		
		string Line = "";
		Line += Client.FirstName + Sep;
		Line += Client.LastName + Sep;
		Line += Client.Email + Sep;
		Line += Client.PhoneNumber+Sep;
		Line += Client.AccountNumber() + Sep;
		Line += Client._PinCode+Sep;
		Line += to_string(Client._AccountBalance);

		return Line;
	}


static vector<clsBankClient> _LoadClientDataFromFile() {
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);
		vector<clsBankClient>vClient;
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (!Client.Is_Empty()) 
				vClient.push_back(Client);

		}
			MyFile.close();

		}


		return vClient;
	}




void _AddNew() {
	AddDataLineToFile(_ConverClientObjectToLine(*this));
}

static void _SaveClientDataToFile(vector<clsBankClient>vClient) {
	fstream MyFile;
	MyFile.open("Client.txt", ios::out);
	string DataLine;
	if (MyFile.is_open()) {
	
		for (clsBankClient& C : vClient) {
			if (C.MarkToDelete == false) {
DataLine = _ConverClientObjectToLine(C);
			MyFile << DataLine << endl;

			}
			

		}
		MyFile.close();

	}


	



}

 void _Update() {
	vector<clsBankClient>vClient = _LoadClientDataFromFile();
	for (clsBankClient& Client : vClient) {
		if (Client.AccountNumber() == AccountNumber()) {
			Client = *this;
		}
		_SaveClientDataToFile(vClient);
	}


}
	 
 

 void AddDataLineToFile(string stDataLine) {
	 fstream File;
	 File.open("Client.txt", ios::out | ios::app);
	 if (File.is_open()) {

		 File << stDataLine<<endl;
		 File.close();
	 }

 }
public:
struct stTransfer {
		string DateTime;
		string AccountNumber1,AccountNumber2;
		float Amount;
		float Balance1,Balance2;
		string UserName;
	};
static stTransfer _ConvertTransferClientToObject(string Line, string Sep = "#//#")
	{

		vector<string>vClient=clsString::Split(Line,Sep);
		stTransfer Client;
		Client.DateTime = vClient[0];
		Client.AccountNumber1 = vClient[1];
		Client.AccountNumber2 = vClient[2];
		Client.Amount = stod (vClient[3]);
		Client.Balance1 = stod (vClient[4]);
		Client.Balance2 = stod(vClient[5]);
		Client.UserName = vClient[6];


		return Client;

	}

static vector<stTransfer> LoadRegistorTransDataFromFile() {
	fstream MyFile;
	MyFile.open("Transfers.txt", ios::in);
	vector<stTransfer>vTransClient;
	if (MyFile.is_open()) {
		string Line;
		while (getline(MyFile, Line)) {
			stTransfer Client = _ConvertTransferClientToObject(Line);
			
				vTransClient.push_back(Client);

		}
		MyFile.close();

	}


	return vTransClient;
}
	clsBankClient(){
		_PinCode="";
		_AccountNumber="";
		_AccountBalance=0.0;
		
	};


	clsBankClient(EnMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	};
	bool Is_Empty() {
		return (_Mode == EnMode::EmptyMode);
	}
	//Read only:
	string AccountNumber() {
		return _AccountNumber;
	}
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print() {
		cout << "Client Card:\n";
		cout << "---------------------\n";
		cout << "\nFirst Name  :" << FirstName;
		cout << "\nLast Name   :" << LastName;
		cout << "\nFull Name   :" << clsPerson::FullName();
		cout << "\nEmail       :" << Email;
		cout << "\nPhone Number:" << PhoneNumber;
		cout << "\nAcc. Number :" << _AccountNumber;
		cout << "\nPin Code    :" << _PinCode;
		cout << "\nAcc. Balance:" << _AccountBalance;
		cout << "\n---------------------\n";


	}



	static clsBankClient Find(string AccountNumber) {
		
		fstream File;
		File.open("Client.txt", ios::in);


		if (File.is_open()) {
			string Line;

			while (getline(File,Line)) {
		clsBankClient Client= _ConvertLinetoClientObject(Line, "#//#");

				if (Client.AccountNumber() == AccountNumber) {
					File.close();
					return Client;
					

				}


			}

			File.close();
		}
		return _GetEmptyClientObject();

	}


	static clsBankClient Find(string AccountNumber,string PinCode) {

		fstream File;
		File.open("Client.txt", ios::in);


		if (File.is_open()) {
			string Line;
			clsBankClient Client = _ConvertLinetoClientObject(Line, "#//#");

			while (getline(File, Line)) {
				if (Client.AccountNumber() == AccountNumber&&Client._PinCode==PinCode) {
					File.close();
					return Client;


				}


			}

			File.close();
		}
		return _GetEmptyClientObject();

	}


static	bool IsClientExist(string AccontNumber) {
		clsBankClient Client=clsBankClient::Find(AccontNumber);
		;
		return !(Client.Is_Empty());

	}

 void Deposit(double Amount) {
	_AccountBalance += Amount;
	Save();
}
 bool  Withdraw(double Amount) {
	 if (Amount > _AccountBalance) {
		 return false;
	 }
	 else {

 _AccountBalance -= Amount;
	 Save();
 }

}	 

 bool Transfer(double Amount, clsBankClient& DesClient) {
	 if (Amount > AccountBalance) {
		 return false;

	 }
	 else
		 Withdraw(Amount);
	 DesClient.Deposit(Amount);
	 return true;
 }
	
static void LoadTransferDataToFile(clsBankClient SourceClient, clsBankClient DesClient,float Amount) {
		fstream File;
		File.open("Transfers.txt", ios::out | ios::app);
		string Line = _ConvertClientsTransferToLine(SourceClient, DesClient, Amount);
		if (File.is_open()) {

			File << Line << endl;

			File.close();
		}


	}


enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1,svFaildAccountNumberExists=3 };

enSaveResults Save() {
	switch (_Mode)
	{
		
case clsBankClient::EmptyMode:
		if (Is_Empty()) 
	
		return enSaveResults::svFaildEmptyObject;
		break;
	case clsBankClient::UbdateMode:
		_Update();
		return enSaveResults::svSucceeded;
		break;
	case  EnMode::AddNewMode:

		if (clsBankClient::IsClientExist(_AccountNumber)) {
			return enSaveResults::svFaildAccountNumberExists;
		}
		else {
			_AddNew();
			_Mode = EnMode::UbdateMode;
			return enSaveResults::svSucceeded;
		}
		break;
	}



}

static clsBankClient GetAddNewClientObject(string AccountNumber) {
	return clsBankClient(EnMode::AddNewMode, "", "", "","", AccountNumber, "", 0);
}

bool Delete() {
	vector<clsBankClient>vClient;
	vClient = _LoadClientDataFromFile();
	for (clsBankClient& Client : vClient) {
		if (Client.AccountNumber() == _AccountNumber) {
			Client.MarkToDelete = true;

			break;
		}
	
	}
	_SaveClientDataToFile(vClient);
	*this = _GetEmptyClientObject();
	return true;
}

static vector<clsBankClient> LoadClientList() {
	return _LoadClientDataFromFile();
}

static double GetTotalBalances() {
	float TotalBalances = 0;
	vector<clsBankClient>vClient = _LoadClientDataFromFile();
	
	for (clsBankClient& Client : vClient) {
		TotalBalances += Client.AccountBalance;

	}


	return TotalBalances;

}
 };





