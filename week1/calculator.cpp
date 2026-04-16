#include <iostream>
using namespace std;                    

int main() {
    double num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Sum: " << num1 + num2 << endl;
    cout << "Difference: " << num1 - num2 << endl;  
    cout << "Product: " << num1 * num2 << endl;
    if (num2 != 0) {
        cout << "Quotient: " << num1 / num2 << endl;
    } else {
        cout << "Cannot divide by zero!" << endl;
    }
    return 0;
}

