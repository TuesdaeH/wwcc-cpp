#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int flips;
    int heads = 0;
    int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;

    for (int i = 0; i < flips; i++) {
        int flip = rand() % 2;

        if (flip == 0) {
            heads++;
        } else {
            tails++;
        }
    }

    double headsPercent = (double)heads / flips * 100;
    double tailsPercent = (double)tails / flips * 100;

    cout << endl;
    cout << "Simulating " << flips << " coin flips..." << endl << endl;

    cout << "Results:" << endl;
    cout << "Heads: " << heads << " (" << headsPercent << "%)" << endl;
    cout << "Tails: " << tails << " (" << tailsPercent << "%)" << endl;

    return 0;
}