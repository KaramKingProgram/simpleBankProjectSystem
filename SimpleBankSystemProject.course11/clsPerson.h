#pragma once
#include<iostream>
using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson() {
		_FirstName="";
		_LastName = "";
		_Email = "";
		_Phone = "";
	};
	clsPerson(string FirstName, string LastName, string Email, string Phone) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;

	};
	void SetFirsName(string FirstName) {
		_FirstName = FirstName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirsName)) string FirstName;

	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	void SetEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	void SetPhoneNumber(string PhoneNumber) {
		_Phone = PhoneNumber;
	}
	string GetPhoneNumber() {
		return _Phone;
	}
	__declspec(property(get = GetPhoneNumber, put = SetPhoneNumber)) string PhoneNumber;
	string FullName() {
		return _FirstName + " " + _LastName;
	}



};

