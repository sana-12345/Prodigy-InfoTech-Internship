#include <iostream>
using namespace std;

int main() {
    double temp;
    char unit;

    cout << "Enter temperature value: ";
    cin >> temp;

    cout << "Enter unit (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;

    if (unit == 'C' || unit == 'c') {
        cout << "Fahrenheit: " << (temp * 9 / 5) + 32 << endl;
        cout << "Kelvin: " << temp + 273.15 << endl;
    }
    else if (unit == 'F' || unit == 'f') {
        cout << "Celsius: " << (temp - 32) * 5 / 9 << endl;
        cout << "Kelvin: " << ((temp - 32) * 5 / 9) + 273.15 << endl;
    }
    else if (unit == 'K' || unit == 'k') {
        cout << "Celsius: " << temp - 273.15 << endl;
        cout << "Fahrenheit: " << ((temp - 273.15) * 9 / 5) + 32 << endl;
    }
    else {
        cout << "Invalid unit entered!" << endl;
    }

    return 0;
}
