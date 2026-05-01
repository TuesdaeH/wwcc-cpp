#include <iostream>
#include <iomanip>
using namespace std;

void convertTemperature(double value, char unit, double &c, double &f, double &k) {
    if (unit == 'C') {
        c = value;
        f = (value * 9/5) + 32;
        k = value + 273.15;
    }
    else if (unit == 'F') {
        f = value;
        c = (value - 32) * 5/9;
        k = c + 273.15;
    }
    else if (unit == 'K') {
        k = value;
        c = value - 273.15;
        f = (c * 9/5) + 32;
    }
}

int main() {
    double value, c, f, k;
    char unit;

    cout << "Enter a temperature value: ";
    cin >> value;

    cout << "Enter the unit (C, F, K): ";
    cin >> unit;

    // make uppercase just in case
    unit = toupper(unit);

    if (unit != 'C' && unit != 'F' && unit != 'K') {
        cout << "Invalid unit." << endl;
        return 0;
    }

    convertTemperature(value, unit, c, f, k);

    cout << fixed << setprecision(2);

    cout << endl << "Temperature Conversions:" << endl;
    cout << "Celsius: " << c << " C" << endl;
    cout << "Fahrenheit: " << f << " F" << endl;
    cout << "Kelvin: " << k << " K" << endl;

    return 0;
}