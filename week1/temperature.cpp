#include <iostream>
using namespace std;

int main() {
    double temperature;
    char unit;

    cout << "Temperature Converter" << endl;

    cout << "Enter temperature value: ";
    cin >> temperature;

    cout << "Enter unit (C for Celsius, F for Fahrenheit): ";
    cin >> unit;

    if (unit == 'C' || unit == 'c') {
        double fahrenheit = (temperature * 9.0 / 5.0) + 32.0;
        cout << temperature << "°C is equal to " << fahrenheit << "°F" << endl;
    } 
    else if (unit == 'F' || unit == 'f') {
        double celsius = (temperature - 32.0) * 5.0 / 9.0;
        cout << temperature << "°F is equal to " << celsius << "°C" << endl;
    }

    return 0;
}