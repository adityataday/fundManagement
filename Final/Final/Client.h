#include <string>
using namespace std;
class Client
{
public:
	Client();
	Client(int u,string p, double b);
	void setUserID(int id);
	void setPassword(string pass);
	int getUserID();
	string getPassword();
	double getBalance();
	bool authentication(int i, string pass);
	double withdraw(double w);
	double deposite(double d);
	void selectSort_userID(Client array[], int n);
	void selectSort_balance(Client array[], int n);

private:
	int userID;
	string password;
	double balance;
};

