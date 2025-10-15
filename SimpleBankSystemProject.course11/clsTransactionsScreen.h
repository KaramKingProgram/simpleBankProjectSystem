#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsValidateInput.h"
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
class clsTransactionsScreen:clsScreen
{
private:
	enum enTransactionsOptions{eDeposit=1,eWithdraw=2,eShowTotalBalance=3,eTransfer=4,eTransferLog=5,eShowMainMenue=6};

	static short _ReadTransactionsMenueOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _DepositScreen(){
		clsDepositScreen::DepositScreen();
	}

	static void _WithdrawScreen(){
		clsWithdrawScreen::WithdrawScreen();
	}

	static void _TransferScreen() {
		clsTransferScreen::ShowTransferScreen();
	}

	static void _TransferLogScreen() {
		clsTransferLogScreen::RegisterLogainScreen();
	}

	static void _ShowTotalBalanceScreen(){
		clsTotalBalancesScreen::TotalBalacne();
	}

	static  void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static	void _PerformMainMenueOption(enTransactionsOptions Option) {
		switch (Option)
		{
		case enTransactionsOptions::eDeposit:
		{
			system("cls");
				_DepositScreen();
				_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsOptions::eWithdraw:
			system("cls");
			_WithdrawScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsOptions::eShowTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsOptions::eTransfer:
			system("cls");
			_TransferScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsOptions::eTransferLog:
			system("cls");
			_TransferLogScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsOptions::eShowMainMenue:
			break;

		
		}



	}
	
public:

	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRigth(clsUser::enPermissions::pTransactions)) {
			return;
		}

		system("cls");
		HeaderScreen("Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenueOption((enTransactionsOptions)_ReadTransactionsMenueOption());
	}


};

