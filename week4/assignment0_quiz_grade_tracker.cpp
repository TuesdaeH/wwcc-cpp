#include <iostream>
#include <string>
using namespace std;

const int NUM_QUIZZES = 5;

char getLetterGrade(double score) {
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else return 'F';
}

int main() {
    int scores[NUM_QUIZZES];

    cout << "QUIZ GRADE TRACKER" << endl;
    cout << "------------------" << endl;

    // Get scores from user
    for (int i = 0; i < NUM_QUIZZES; i++) {
        cout << "Enter score for Quiz " << i + 1 << " (0-100): ";
        cin >> scores[i];
    }

    // Calculate average
    double total = 0;
    for (int i = 0; i < NUM_QUIZZES; i++) {
        total += scores[i];
    }
    double average = total / NUM_QUIZZES;

    // Find highest and lowest
    int highest = scores[0];
    int lowest = scores[0];
    int highestIndex = 0;
    int lowestIndex = 0;

    for (int i = 1; i < NUM_QUIZZES; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
            highestIndex = i;
        }
        if (scores[i] < lowest) {
            lowest = scores[i];
            lowestIndex = i;
        }
    }

    // Grade distribution
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;
    for (int i = 0; i < NUM_QUIZZES; i++) {
        char grade = getLetterGrade(scores[i]);
        if (grade == 'A') countA++;
        else if (grade == 'B') countB++;
        else if (grade == 'C') countC++;
        else if (grade == 'D') countD++;
        else countF++;
    }

    // Display results
    cout << "\nQuiz Results:" << endl;
    for (int i = 0; i < NUM_QUIZZES; i++) {
        cout << "  Quiz " << i + 1 << ":  " << scores[i] << "  (" << getLetterGrade(scores[i]) << ")" << endl;
    }

    cout << "\nStatistics:" << endl;
    cout << "  Average score:  " << average << endl;
    cout << "  Highest score:  " << highest << "  (Quiz " << highestIndex + 1 << ")" << endl;
    cout << "  Lowest score:   " << lowest << "  (Quiz " << lowestIndex + 1 << ")" << endl;
    cout << "  Overall grade:  " << getLetterGrade(average) << endl;

    cout << "\nGrade Distribution:" << endl;
    cout << "  A: " << countA << endl;
    cout << "  B: " << countB << endl;
    cout << "  C: " << countC << endl;
    cout << "  D: " << countD << endl;
    cout << "  F: " << countF << endl;

    return 0;
}