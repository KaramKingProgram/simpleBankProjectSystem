#pragma once
#include"clsDate.h"

class clsInputValidate
{




public:
	static bool IsNumberBetween(int iNumber, int From, int To) {

		return ((iNumber >= From) && (iNumber <= To));

	}

	static bool IsNumberBetween(double dNumber, double From, double To) {
		return ((dNumber >= From) && (dNumber <= To));
	}

	static bool IsNumberBetween(float fNumber, float From, float To) {
		return ((fNumber >= From) && (fNumber <= To));
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo) {

		if (clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom) &&
			(clsDate::IsDate1BeforeDate2(Date, DateTo)) || clsDate::IsDate1EqualDate2(Date, DateTo))
		{
			return true;
		}
		if (clsDate::IsDate1AfterDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo) &&
			(clsDate::IsDate1BeforeDate2(Date, DateFrom)) || clsDate::IsDate1EqualDate2(Date, DateFrom))
		{
			return true;
		}

		return false;


	}
	static string ReadString() {
		string S;
		getline(cin >> ws, S);
		return S;
	}
	static float ReadFloatNumber() {
		float F;
		cin >> F;
		return F;

	}
	static int ReadIntNumber(string ErrorMessage) {
		int x;
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;

		}


		return x;
	}

	static double ReadDoubleNumber(string ErrorMessage) {
		double x;
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;

		}


		return x;
	}

	static int ReadIntNumberBetween(int From, int To, string  ErrorMessage) {
		int x = 0;
		while (true) {
			cin >> x;
			if (IsNumberBetween(x, From, To)) {
				return x;
			}
			else {
				cout << ErrorMessage;
			}


		}


	}

	static short ReadShortNumberBetween(short From, short To, string  ErrorMessage) {
		short x = 0;
		while (true) {
			cin >> x;
			if (IsNumberBetween(x, From, To)) {
				return x;
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << ErrorMessage;
			}


		}


	}



	static double ReadDoubleNumberBetween(double From, double To, string  ErrorMessage) {
		double x = 0;
		while (true) {
			cin >> x;
			if (IsNumberBetween(x, From, To)) {
				return x;
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << ErrorMessage;
			}


		}


	}

	static bool IsValid(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

};


