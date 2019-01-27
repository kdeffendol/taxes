//kelsey deffendol
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double income = -1;
    char accountType = 'a';
    double tax;
    char anotherCalc = 'y';

    //set decimal place
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    while (anotherCalc == 'y') {
        //get income
        while (income < 0) {
            cout << "Please enter in your taxable income." << endl << "(This must be a positive value): ";
            cin >> income;
        }

        //error checking
        while (accountType != 'm' && accountType != 's') {
            cout << "Please enter m if married and filing joint return, or s if filing a single return: ";
            cin >> accountType;
        }


        //single filing
        if (accountType == 's') {
            if (income <= 863) {
                tax = income * 0.023;
            }
            else if (income >= 864 && income <= 2588) {
                tax = (income - 863) * 0.033 + 25;
            }
            else if (income >= 2589 && income <= 4313) {
                tax = (income - 2588) * 0.052 + 85;
            }
            else if (income > 4313) {
                tax = (income - 4313) * 0.075 + 181;
            }
        }

        if (accountType == 'm') {
            if (income <= 1726) {
                tax = income * 0.023;
            }
            else if (income >= 1727 && income <= 5176) {
                tax = (income - 1726) * 0.033 + 40;
            }
            else if (income >= 5177 && income <= 8626) {
                tax = (income - 5176) * 0.052 + 175;
            }
            else if (income > 8626) {
                tax = (income - 8626) * 0.075 + 390;
            }
        }

        //print output
        cout<<endl;
        cout << "Your taxable income is $" << income << endl;
        cout << "and you are filing a ";
        if (accountType == 's') {
            cout << "single";
        }
        else {
            cout << "joint";
        }
        cout << " return." << endl;
        cout << "Your income tax will be $" << tax << endl;

        do {
            cout << "Would you like to do another calculation (y or n)? ";
            cin >> anotherCalc;
        } while (anotherCalc != 'y' && anotherCalc != 'n');

        income = -1;
        accountType = 'a';
        
    }
}