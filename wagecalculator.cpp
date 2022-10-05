#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    cout << "How many hours did you work?" << endl;
    int workedhr;
    cin >> workedhr;

    if (workedhr < 0) {
        cout << "You have entered a negative number for worked hour." << endl;
        cout << "Terminating the program." << endl;
        return 0;
    }

    cout << "How much do you make per hour?" << endl;
    double hourlywage;
    cin >> hourlywage;

    if (hourlywage < 0) {
        cout << "Your hourly wage is less than 0. Please try again:" << endl;
        cin >> hourlywage;
    }
    if (hourlywage < 0) {
        cout << "Your hourly wage is less than 0. Please try again:" << endl;
        cin >> hourlywage;
        cout << endl;
    }
    double grosspay;
    if (workedhr <= 40) {
        grosspay = (workedhr * hourlywage);
    }
    else if (workedhr > 40) {
        grosspay = 40 * hourlywage + (workedhr - 40) * hourlywage * 1.5;
    }
    double amountofdeductions;
    if (grosspay <= 100) {
        amountofdeductions = (double)(double)(double(grosspay * 2) / (double)100);
    }
    else if (grosspay > 100 && grosspay <= 500) {
        amountofdeductions = (double)(double)(grosspay * 5) / (double)100;
    }
    else if (grosspay > 500) {
        amountofdeductions = (double)(double)(grosspay * 9) / (double)100;
    }
    double netpay = grosspay - amountofdeductions;

    cout << "Wage Calculator" << endl;
    cout << "Hours Worked                  " << workedhr << endl;
    cout << "Hourly Wage                 " << fixed << setprecision(2) << hourlywage << endl;
    cout << "---------------------------------" << endl;
    cout << "Gross Pay                 " << grosspay << endl;
    cout << "Deductions                  " << amountofdeductions << endl;
    cout << "---------------------------------" << endl;
    cout << "Net Pay                   " << fixed << setprecision(2) << netpay << endl;




    return 0;
}
