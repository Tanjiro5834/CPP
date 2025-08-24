#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

#define max_attempts 5

using namespace std;

class BankAccount {
private:
	int accountNumber;
	string accountHolderName;
	double balance;
	string password;

public:
	BankAccount(int a, string ac, double b, string p) {
		accountNumber = a;
		accountHolderName = ac;
		balance = b;
		password = p;
	}
	int getAccountNumber() const {
		return accountNumber;
	}
	string getAccountHolder() const {
		return accountHolderName;
	}
	double getBalance() const {
		return balance;
	}
	string getPassword() const {
		return password;
	}
	void setBalance(double bal) {
		balance = bal;
	}
	void setPassword(string p) {
		password = p;
	}
	void displayData() const{
		cout << "Account number: " << accountNumber << ", Account holder name: " << accountHolderName << ", Current balance: " << balance << endl;
	}
};

vector<BankAccount> db;

int generateUniqueAccountNumber() { return rand() % 100 + 1; }

void createAccount() {
	string accountHolder, password;
	double balance;
	cout << "Account holder: ";
	getline(std::cin, accountHolder);

	cout << "Balance: ";
	cin.ignore();
	cin >> balance;

	cout << "Password (recommended 8 characters): ";
	getline(cin, password);

	if (accountHolder.empty() && balance == 0 && password.size() <= 8) {
		cout << "Enter account holder name and valid balance.\n";
	}
	else {
		int accountNumber = generateUniqueAccountNumber();
		BankAccount newAcc(accountNumber, accountHolder, balance, password);
		db.push_back(newAcc);
		cout << "Account saved." << endl;
	}

}

bool authenticate(string name, string password) {
	for (BankAccount bA : db) {
		if (bA.getAccountHolder() == name && bA.getPassword() == password) return true;
	}
	return false;
}

void logger() {
	string name, password;
	int attemptCount = 1;

	while (attemptCount < max_attempts) {
		cout << "Enter account holder name: ";
		getline(cin, name);
		cout << "Enter password: ";
		getline(cin, password);

		attemptCount++;
		if (authenticate(name, password)) {
			optionOperator();
			break;
		}
		else {
			cout << "Invalid account holder name and password, Remaining attempts: " << (max_attempts - attemptCount) << "/5" << endl;
		}
	}
}

void optionOperator() {
	cout << "1. Deposit\n2. Withdraw\n3. Balance Display";
	cout << "YOUR CHOICE: ";

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		logger();

	}
}

int main() {
	srand(time(0));
}