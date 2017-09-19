#include "Client.h"
#include <iostream>
#include <string>

using namespace std;

Client::Client() {
	userID = 0;
	password = " ";
	balance = 0;
}

Client::Client(int u, string p, double b)
{
	userID = u;
	password = p;
	balance = b;
}

void Client::setUserID(int id)
{
	userID = id;
}

void Client::setPassword(string pass)
{
	password = pass;
}


int Client::getUserID()
{
	return userID;
}

string Client::getPassword()
{
	return password;
}

double Client::getBalance()
{
	return balance;
}

bool Client::authentication(int i, string pass)
{
	if (i == userID && pass == password) {
		return true;
	}
	else {
		return false;
	}
}

double Client::withdraw(double w)
{
		balance -= w;
		return balance;
}

double Client::deposite(double d)
{
	balance += d;

	return balance;
}

void Client::selectSort_userID(Client array[], int n)
{
		int pos_min;
		Client temp;

		for (int i = 0; i < n - 1; i++)
		{
			pos_min = i;

			for (int j = i + 1; j < n; j++)
			{

				if (array[j].getUserID() < array[pos_min].getUserID())
					pos_min = j;

			}

			if (pos_min != i)
			{
				temp = array[i];
				array[i] = array[pos_min];
				array[pos_min] = temp;
			}
		}
}

void Client::selectSort_balance(Client array[], int n)
{
	int pos_min;
	Client temp;

	for (int i = 0; i < n - 1; i++)
	{
		pos_min = i;

		for (int j = i + 1; j < n; j++)
		{

			if (array[j].getBalance() < array[pos_min].getBalance())
				pos_min = j;

		}

		if (pos_min != i)
		{
			temp = array[i];
			array[i] = array[pos_min];
			array[pos_min] = temp;
		}
	}
}










