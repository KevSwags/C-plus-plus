#include <iostream>
using namespace std;
void prime_number() {

	int number;

	cout << "PRIME NUMBER:" << endl;

	cout << "Please enter a positive integer: ";

	cin >> number;

	while (number <= 0) {

		cout << "Positive integer: ";

		cin >> number;

	}

	for (int i = 2; i < number; i++) {

		for (int j = 2; j <= i; j++) {

			if (i == j) {

				cout << i << " ";

				break;

			}

			else if (i % j == 0) {

				break;

			}

			else if (i % j != 0) {

				continue;

			}

		}

	}

	cout << endl;
}
void perfect_number() {

	cout << endl;

	cout << "PERFECT NUMBER:" << endl;

	int n;

	int s = 0;

	cout << "Enter a positive number: ";

	cin >> n;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j < i; j++) {

			if (i % j == 0) {

				s += j;

				continue;

			}

			else {

				continue;

			}

		}

		if (s == i) {

			cout << i << endl;

			s = 0;

		}

		else {

			s = 0;

		}

	}
	void leap_year() {

		cout << endl;

		cout << "LEAP YEAR:" << endl;

		cout << "Enter a year: ";

		int year;

		cin >> year;

		if (year % 100 != 0) {

			if (year % 4 == 0)

				cout << year << " is a leap year!";

			else if (year % 400 == 0) {

				cout << year << " is a leap year!";

			}

			else {

				cout << year << " is NOT a leap year!";

			}

		}

		else {

			cout << year << " is NOT a leap year!";

		}
	}
	void reverse_integer() {

		cout << endl;

		cout << endl;

		cout << "REVERSE INTEGER:" << endl;

		cout << "Enter a positive integer: ";

		int integer;

		cin >> integer;

		while (integer < 0) {

			cout << "Enter a positive integer: ";

			cin >> integer;

		}

		if (integer <= 9) {

			cout << integer;

			return;

		}

		while (integer > 0)

		{

			cout << integer % 10;

			integer = integer / 10;

		}
	}
	int main() {

		prime_number();


		perfect_number();

		eap_year();


		reverse_integer();


		return 0;
	}