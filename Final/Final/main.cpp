#include "Client.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;


int start_choice();
int client_menu(int x);
int manager_menu();
string passwordProtection();


int main() {

	Client co(0, " ", 0);

	Client clientArray[1000];
	int cursor;
	ifstream clientFile("client_details.txt");

	int accountNum;
	string password;
	double initalBal;

	int  arrayCount = 0;
	int client_counter = 0;
	while (!clientFile.eof()) {
		clientFile >> accountNum >> password >> initalBal;
		clientArray[arrayCount] = Client(accountNum, password, initalBal);
		arrayCount++;
		client_counter++;
	}

	int initialChoice = start_choice();

	if (initialChoice == 1) {

		string managerID_userIN;
		string passwordManager_userIN;

		string managerID = "admin";
		string passwordManager = "224";

		cout << "Please Enter your Manager userID: ";
		cin >> managerID_userIN;

		cout << "Please enter your password: ";
		passwordManager_userIN = passwordProtection();

		if (managerID_userIN == managerID && passwordManager_userIN == passwordManager) {
			cout << "\nLOGIN SUCCESSFUL!" << endl;

			int managerChoice;

			do {

				managerChoice = manager_menu();

				if (managerChoice == 1) {

					int newuserID;
					string newpassword;
					double newBalance;

					fstream addClient("client_details.txt", ios::in | ios::out | ios::app);

					cout << "Create an userID for the new user: ";
					cin >> newuserID;

					cout << "Create a password for the new user: ";
					cin >> newpassword;

					cout << "Enter an initial balance for the user: ";
					cin >> newBalance;

					addClient << endl << newuserID << " " << newpassword << " " << newBalance;

					cout << endl;
					cout << "REGISTRATION SUCESSFULL" << endl;
					cout << newuserID << " welcome to SBU BANK !" << endl;
				}

				else if (managerChoice == 2) {

					int userID;

					cout << "Enter client's userID: ";
					cin >> userID;

					bool correct_detail = false;
					int temp;

					for (int i = 0; i < client_counter; i++) {
						if (clientArray[i].getUserID() == userID) {
							correct_detail = true;
							temp = i;
						}
					}

					if (correct_detail == true) {
						cout << "This is a valid Client" << endl;
						cout << "Client's Password: " << clientArray[temp].getPassword() << endl;
						cout << "Client's Balance: " << clientArray[temp].getBalance() << endl;
					}

					else {
						cout << "Invalid client userID" << endl;
					}
				}

				else if (managerChoice == 3) {

					cout << "UserID" << "\t" << "Password" << "\t" << "Balance" << endl;
					cout << "------" << "\t" << "--------" << "\t" << "-------" << endl;

					for (int i = 0; i < client_counter; i++) {
						cout << clientArray[i].getUserID() << "\t" << clientArray[i].getPassword() << "\t\t" << clientArray[i].getBalance() << endl;
					}

					int choice_sort;
					do {

						cout << endl;
						cout << "Select type of sort" << endl;
						cout << "1 - Sort by userID" << endl;
						cout << "2 - Sort by Balance" << endl;

						cout << endl;
						cin >> choice_sort;
					} while (choice_sort != 1 && choice_sort != 2);

					if (choice_sort == 1) {

						co.selectSort_userID(clientArray, client_counter);

						cout << "UserID" << "\t" << "Password" << "\t" << "Balance" << endl;
						cout << "------" << "\t" << "--------" << "\t" << "-------" << endl;

						for (int i = 0; i < client_counter; i++) {
							cout << clientArray[i].getUserID() << "\t" << clientArray[i].getPassword() << "\t\t" << clientArray[i].getBalance() << endl;
						}
					}
					else if (choice_sort == 2) {

						co.selectSort_balance(clientArray, client_counter);

						cout << "UserID" << "\t" << "Password" << "\t" << "Balance" << endl;
						cout << "------" << "\t" << "--------" << "\t" << "-------" << endl;

						for (int i = 0; i < client_counter; i++) {
							cout << clientArray[i].getUserID() << "\t" << clientArray[i].getPassword() << "\t\t" << clientArray[i].getBalance() << endl;
						}
					}

				}

				else if (managerChoice == 4) {
					int userID;

					cout << "Enter client's userID: ";
					cin >> userID;

					bool correct_detail = false;
					int temp;

					for (int i = 0; i < client_counter; i++) {
						if (clientArray[i].getUserID() == userID) {
							correct_detail = true;
							temp = i;
						}
					}

					if (correct_detail == true) {
						int choice_change;
						do {

							cout << endl;
							cout << "Select data to modify" << endl;
							cout << "1 - Modify userID" << endl;
							cout << "2 - Modify password" << endl;

							cout << endl;
							cin >> choice_change;
						} while (choice_change != 1 && choice_change != 2);

						if (choice_change == 1) {
							int newUserId;

							cout << "Enter a new userID: ";
							cin >> newUserId;

							bool possible = true;

							for (int i = 0; i < client_counter; i++) {
								if (clientArray[i].getUserID() == newUserId) {
									possible = false;
								}
							}

							if (possible == true) {
								clientArray[temp].setUserID(newUserId);
								cout << "userID changed!" << endl;
							}
							else {
								cout << "MODIFICATION FAILED: userID already exists" << endl;
							}

						}
						else if (choice_change == 2) {
							string newPassword;

							cout << "Enter a new password: ";
							cin >> newPassword;

							clientArray[temp].setPassword(newPassword);

							cout << "Password changed!" << endl;
						}
					}
				}

				else if (managerChoice == 5) {
					int userID;

					cout << "Enter client's userID that you want to delete: ";
					cin >> userID;

					bool correct_detail = false;
					int temp;

					for (int i = 0; i < client_counter; i++) {
						if (clientArray[i].getUserID() == userID) {
							correct_detail = true;
							temp = i;
						}
					}

					if (correct_detail == true) {
						clientArray[temp].setUserID(0);

						co.selectSort_userID(clientArray, client_counter);

						for (int i = 1; i < client_counter; i++) {
							clientArray[i - 1] = clientArray[i];
						}
						client_counter--;

						cout << "Client removed!" << endl;
					}
					else {
						cout << "UPDATED FAILED: INVALID userID" << endl;
					}
				}

				else if (managerChoice == 6) {
					cout << "Logout Successful..." << endl;
					cout << "See you soon!" << endl;
					break;
				}

			} while (managerChoice <= 6);

		}

		else {
			cout << "\nLOGIN FAILED! INVALID USERID OR PASSWORD" << endl;
		}

	}
	else if (initialChoice == 2) {

		int userID;
		string password_userIN;

		bool login = false;

		cout << "Please Enter your Client userID: ";
		cin >> userID;

		cout << "Please enter your password: ";
		password_userIN = passwordProtection();

		for (int i = 0; i < client_counter; i++) {
			if ((clientArray[i].authentication(userID, password_userIN) == true)) {
				login = true;
				cursor = i;
			}
		}

		if (login == true) {
			cout << "\nLOGIN SUCCESSFUL!" << endl;

			if (clientArray[cursor].getBalance() < 100) {
				cout << "Account balance is below $100" << endl;
			}

			int clientChoice;

			do {
				clientChoice = client_menu(userID);

				if (clientChoice == 1) {
					cout << "Your current balance is: " << clientArray[cursor].getBalance() << endl;
				}
				else if (clientChoice == 2) {

					double withdraw;
					cout << "Enter the amount of money you would like to withdraw: ";
					cin >> withdraw;

					if (clientArray[cursor].getBalance() - 25 < withdraw) {
						cout << "TRANSACTION FAILED: BALANCE LESS THAN $25" << endl;
					}
					else {
						double newBalance = clientArray[cursor].withdraw(withdraw);
						cout << "Your new balance is: " << newBalance << endl;
					}
				}

				else if (clientChoice == 3) {

					double deposit;
					cout << "Enter the amount of money you would like to deposit: ";
					cin >> deposit;

					double newBalance = clientArray[cursor].deposite(deposit);
					cout << "Your new balance is: " << newBalance << endl;
				}

				else if (clientChoice == 4) {

					int transfer_clientID;
					double transfer_money;

					cout << "Enter the userID of the client to which you would like to transfer money: ";
					cin >> transfer_clientID;

					bool correct_transfer = false;
					int temp;

					for (int i = 0; i < client_counter; i++) {
						if (clientArray[i].getUserID() == transfer_clientID) {
							correct_transfer = true;
							temp = i;
						}
					}

					if (correct_transfer == true) {

						cout << "Enter the amount you would like to transfer: ";
						cin >> transfer_money;

						if (clientArray[cursor].getBalance() - 25 < transfer_money) {
							cout << "TRANSACTION FAILED: BALANCE LESS THAN $25" << endl;
						}
						else {

							double newBalance_cursor = clientArray[cursor].withdraw(transfer_money);
							double newBalance_transfer = clientArray[temp].deposite(transfer_money);
							cout << "Your new balance is: " << newBalance_cursor << endl;

						}

					}

					else {
						cout << "TRANSACTION FAILED: INNCORRECT USERID" << endl;
					}

				}

				else if (clientChoice == 5) {
					cout << "Logout Successful..." << endl;
					cout << "Thank you for using our services!" << endl;
					break;
				}

			} while (clientChoice <= 5);

		}
		else {
			cout << "\nLOGIN FAILED! INVALID USERID OR PASSWORD" << endl;
		}

	}
	else if (initialChoice == 3) {
		cout << "GOOD BYE!" << endl;
	}

	ofstream overwrite("client_details.txt");

	for (int i = 0; i < client_counter; i++) {
		overwrite << clientArray[i].getUserID() << " " << clientArray[i].getPassword() << " " << clientArray[i].getBalance();

		if (i < client_counter - 1) {
			overwrite << endl;
		}
	}


	clientFile.close();
	system("PAUSE");
	return 0;

}


int start_choice() {

	int choice;
	do {
		cout << "```````````````````````````````````````" << endl;
		cout << "          Welcome TO SBU BANK          " << endl;
		cout << "```````````````````````````````````````" << endl;

		cout << "Type of user" << endl;
		cout << "1 - Manager" << endl;
		cout << "2 - Client" << endl;
		cout << "3 - Quit" << endl;

		cout << endl;
		cin >> choice;

	} while (choice != 1 && choice != 2 && choice != 3);

	return choice;
}

int client_menu(int x) {
	int choice;
	int userID = x;

	do {
		cout << "```````````````````````````````````````" << endl;
		cout << "              Client Menu              " << endl;
		cout << "```````````````````````````````````````" << endl;

		cout << "Welcome " << userID << "!" << endl;
		cout << "Please choose appropriate number from the following options to continue: " << endl;
		cout << "1 - Check Balance" << endl;
		cout << "2 - Withdraw Money" << endl;
		cout << "3 - Deposit Money" << endl;
		cout << "4 - Transfer Money" << endl;
		cout << "5 - Log Out" << endl;

		cout << endl;
		cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

	return choice;
}

int manager_menu() {
	int choice;

	do {
		cout << "```````````````````````````````````````" << endl;
		cout << "             Manager Menu              " << endl;
		cout << "```````````````````````````````````````" << endl;

		cout << "Welcome back Manager !" << endl;
		cout << "Please choose appropriate number from the following options to continue: " << endl;
		cout << "1 - Register new user" << endl;
		cout << "2 - Search Customer Info" << endl;
		cout << "3 - Get Customer List" << endl;
		cout << "4 - Modify Customer Details" << endl;
		cout << "5 - Delete account" << endl;
		cout << "6 - Log Out" << endl;

		cout << endl;
		cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);

	return choice;
}

string passwordProtection() {

	string pass = "";
	char ch, a;

	ch = _getch();
	while (ch != 13)
	{
		if (ch != 8)
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}

		if (ch == 8)
		{
			pass = pass.substr(0, pass.length() - 1);
			cout << '\b';
			cout << " ";
			cout << '\b';
			ch = _getch();
		}
	}

	return pass;

}

