#include <iostream>
#include <iomanip>
using namespace std;

int conversionCount = 0;

// USD → Euro
double dollarToEuro(double amount) {
    static int count = 0;
    count++;
    conversionCount++;
    return amount * 0.85;
}

// USD → Pound
double dollarToPound(double amount) {
    static int count = 0;
    count++;
    conversionCount++;
    return amount * 0.74;
}

// USD → Yen
double dollarToYen(double amount) {
    static int count = 0;
    count++;
    conversionCount++;
    return amount * 110.33;
}

// Get total conversions
int getConversionCount() {
    return conversionCount;
}

int main() {
    int choice;
    double amount;
    char again;

    do {
        cout << "CURRENCY CONVERTER\n";
        cout << "------------------\n";
        cout << "1. Convert USD to Euro (EUR)\n";
        cout << "2. Convert USD to British Pound (GBP)\n";
        cout << "3. Convert USD to Japanese Yen (JPY)\n";
        cout << "4. Exit\n\n";

        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 4) break;

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice.\n\n";
            continue;
        }

        cout << "Enter amount in USD: ";
        cin >> amount;

        cout << fixed << setprecision(2);

        if (choice == 1) {
            double result = dollarToEuro(amount);
            cout << amount << " USD = " << result << " EUR\n";
        }
        else if (choice == 2) {
            double result = dollarToPound(amount);
            cout << amount << " USD = " << result << " GBP\n";
        }
        else if (choice == 3) {
            double result = dollarToYen(amount);
            cout << amount << " USD = " << result << " JPY\n";
        }

        cout << "\nNumber of conversions performed: " 
             << getConversionCount() << "\n\n";

        cout << "Would you like to perform another conversion? (y/n): ";
        cin >> again;
        cout << endl;

    } while (again == 'y' || again == 'Y');

    cout << "Thank you for using the Currency Converter!\n";

    return 0;
}