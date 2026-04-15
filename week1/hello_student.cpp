#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    string favorite;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Hello, " << name << "! Welcome to C++!" << endl;

    cout << "What is your favorite food? ";
    getline(cin, favorite);


    cout << name << ", I like "  << favorite << " too!" << endl;

    return 0;
}