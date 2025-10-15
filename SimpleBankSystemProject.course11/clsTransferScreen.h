#pragma once
#include <iostream>
#include<fstream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include"clsValidateInput.h"
#include"Global.h"
class clsTransferScreen :protected clsScreen
{

private:
    

  
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
      
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadFloatNumber();
        }
        return Amount;
    }

public:
   
    static void ShowTransferScreen()
    {

        HeaderScreen("\tTransfer Screen");
        cout << "\nPlease Enter Account Number to Transfer From: ";
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(SourceClient);
        cout << "\nPlease Enter Account Number to Transfer To: ";
        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);


        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }
        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);

        clsBankClient::LoadTransferDataToFile(SourceClient, DestinationClient,Amount);
    }

};

;

