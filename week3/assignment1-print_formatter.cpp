#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

// Format integer with commas
string format(int num) {
    string str = to_string(num);
    string result = "";
    int count = 0;

    for (int i = str.length() - 1; i >= 0; i--) {
        result = str[i] + result;
        count++;

        if (count == 3 && i != 0) {
            result = "," + result;
            count = 0;
        }
    }
    return result;
}

// Format double to 2 decimal places
string format(double num) {
    stringstream ss;
    ss << fixed << setprecision(2) << num;
    return ss.str();
}

// Format double with custom precision
string format(double num, int precision) {
    stringstream ss;
    ss << fixed << setprecision(precision) << num;
    return ss.str();
}

// Capitalize first letter of each word
string format(string text) {
    if (text.length() == 0) return text;

    text[0] = toupper(text[0]);

    for (int i = 1; i < text.length(); i++) {
        if (text[i - 1] == ' ') {
            text[i] = toupper(text[i]);
        }
    }
    return text;
}

int main() {
    // Integer test
    int num = 1234567;
    cout << "Integer formatting:" << endl;
    cout << "Original: " << num << endl;
    cout << "Formatted: " << format(num) << endl << endl;

    // Double default
    double d = 45.6789;
    cout << "Double formatting (default 2 decimal places):" << endl;
    cout << "Original: " << d << endl;
    cout << "Formatted: " << format(d) << endl << endl;

    // Double custom
    cout << "Double formatting (custom decimal places):" << endl;
    cout << "Original: " << d << " with precision 3" << endl;
    cout << "Formatted: " << format(d, 3) << endl << endl;

    // String formatting
    string text = "hello world of c++ programming";
    cout << "String formatting:" << endl;
    cout << "Original: \"" << text << "\"" << endl;
    cout << "Formatted: \"" << format(text) << "\"" << endl;

    return 0;
}