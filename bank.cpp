#include <iostream>
using namespace std;

void Account(string name, string password) {
	cout << "Welcome " << name << " Here is your current balance:" << endl;
	cout << endl;

	cout << "Checking: " << endl;
	int checking = 4500;
	cout << "$" << checking << endl;

	cout << endl;

	cout << "Saving: " << endl;
	int saving = 7960;
	cout << "$" << saving << endl;

	cout << endl;
}

int main() {
	cout << "Welcome to Swag of America." << endl;
	cout << endl;

	cout << "Type 'N' - To sign up: " << endl;
	char login;
	cin >> login;

	string password;
	string name;

	if (login == 'N') {
		cout << "Create your account! " << endl;
		cout << endl;

		cout << "Create your Username: ";
		cin >> name;

		cout << "Hello, " << name << " please create your password: ";
		cin >> password;

		cout << endl;
	}

	cout << "Great! Know let's LOG YOU IN!" << endl;

	cout << "Username: ";
	string login_name;
	cin >> login_name;

	cout << "Password: ";
	string login_password;
	cin >> login_password;

	while (name != login_name) {
		cout << "Your username is INCORRECT! Please try again..." << endl;
		cout << endl;
		cout << "Username: ";
		cin >> login_name;
	}

	while (password != login_password) {
		cout << "Your password is INCORRECT! Please try again..." << endl;
		cout << endl;
		cout << "Password: ";
		cin >> login_password;
	}

	Account(login_name, login_password);

	cout << "What would you like to do: " << endl;
	cout << "'D' - Deposit" << endl;
	cout << "'W' - Withdraw" << endl;
	cout << "'T' - Transfer" << endl;

	char action;
	cin >> action;

	cout << endl;

	if (action == 'D') {
		cout << "How much would you like to deposit: ";
		int Amount_Deposit;
		cin >> Amount_Deposit;

		cout << endl;

		cout << "Where would you like to add your deposit: " << endl;
		cout << "'C' - Checking" << endl;
		cout << "'S' - Savings" << endl;

		char add;
		cin >> add;

		cout << endl;

		if (add == 'C') {
			cout << "Checking: " << endl;
			int new_checking = 4500 + Amount_Deposit;
			cout << "$" << new_checking << endl;
		}
		else {
			cout << "Saving: " << endl;
			int new_saving = 7960 + Amount_Deposit;
			cout << "$" << new_saving << endl;
		}
	}

	else if (action == 'W') {
		cout << "How much would you like to Withdraw: ";
		int Amount_Withdraw;
		cin >> Amount_Withdraw;

		cout << "Where would you like to remove your amount: " << endl;
		cout << "'C' - Checking" << endl;
		cout << "'S' - Savings" << endl;

		char add;
		cin >> add;

		if (add == 'C') {
			cout << "Checking: " << endl;
			int new_checking = 4500 - Amount_Withdraw;
			cout << "$" << new_checking << endl;
		}
		else {
			cout << "Saving: " << endl;
			int new_saving = 7960 - Amount_Withdraw;
			cout << "$" << new_saving << endl;
		}
	}

	else {
		cout << "What account would you like to move your amount from: " << endl;

		cout << "Checking: " << endl;
		cout << "'C'" << endl;
		int checking = 4500;
		cout << "$" << checking << endl;

		cout << endl;

		cout << "Saving: " << endl;
		cout << "'S'" << endl;
		int saving = 7960;
		cout << "$" << saving << endl;

		cout << endl;

		cout << "--> ";
		char transfer;
		cin >> transfer;

		if (transfer == 'C') {
			cout << "How much do want to transfer: ";
			int checking_transfer;
			cin >> checking_transfer;

			cout << endl;

			cout << "TRANSFER COMPLETE!" << endl;

			cout << endl;

			cout << "Updated Checking: " << endl;
			int checking = 4500;
			cout << "$" << checking - checking_transfer << endl;

			cout << endl;

			cout << "Updated Saving: " << endl;
			int saving = 7960;
			cout << "$" << saving + checking_transfer << endl;
		}

		else {
			cout << "How much do you want to transfer: ";
			int savings_transfer;
			cin >> savings_transfer;

			cout << "TRANSFER COMPLETE!" << endl;

			cout << "Updated Checking: " << endl;
			int checking = 4500;
			cout << "$" << checking + savings_transfer << endl;

			cout << endl;

			cout << "Updated Saving: " << endl;
			int saving = 7960;
			cout << "$" << saving - savings_transfer << endl;
		}
	}
	return 0;
}