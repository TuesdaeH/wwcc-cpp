#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Student {
    string lastName;
    string firstName;
    int g1, g2, g3;
    double average;
    int high;
    int low;
};

int main() {
    ifstream inFile("grades.txt");

    if (!inFile) {
        cerr << "Error: could not open grades.txt" << endl;
        return 1;
    }

    cout << "Reading records from grades.txt..." << endl;

    vector<Student> students;
    string line;

    while (getline(inFile, line)) {
        if (line.empty() || line[0] == '#') continue;

        stringstream ss;
        ss.str(line);

        Student s;
        ss >> s.lastName >> s.firstName >> s.g1 >> s.g2 >> s.g3;

        s.high = max({s.g1, s.g2, s.g3});
        s.low  = min({s.g1, s.g2, s.g3});

        int total = s.g1 + s.g2 + s.g3;
        s.average = (double)total / 3;

        students.push_back(s);
    }
    inFile.close();

    cout << students.size() << " students loaded." << endl << endl;

    ofstream outFile("grade_report.txt", ios::app);
    if (!outFile) {
        cerr << "Error: could not open grade_report.txt" << endl;
        return 1;
    }

    auto printReport = [&](ostream& out) {
        out << "GRADE REPORT" << endl;
        out << string(20, '-') << endl;

        out << left
            << setw(20) << "Name"
            << setw(7)  << "Avg"
            << setw(7)  << "High"
            << setw(7)  << "Low"
            << endl;
        out << string(20, '-') << endl;

        double classTotal = 0;
        int topIdx = 0, lowIdx = 0;

        for (int i = 0; i < (int)students.size(); i++) {
            Student& s = students[i];
            string name = s.lastName + ", " + s.firstName;

            out << left  << setw(20) << name
                << right << setw(7)  << fixed << setprecision(1) << s.average
                << right << setw(7)  << s.high
                << right << setw(7)  << s.low
                << endl;

            classTotal += s.average;
            if (s.average > students[topIdx].average) topIdx = i;
            if (s.average < students[lowIdx].average) lowIdx = i;
        }

        double classAvg = classTotal / students.size();

        out << endl << "CLASS STATISTICS" << endl;
        out << string(20, '-') << endl;
        out << fixed << setprecision(1);
        out << "Class average: " << classAvg << endl;
        out << "Top student:   "
            << students[topIdx].lastName << ", "
            << students[topIdx].firstName
            << " (" << students[topIdx].average << ")" << endl;
        out << "Low student:   "
            << students[lowIdx].lastName << ", "
            << students[lowIdx].firstName
            << " (" << students[lowIdx].average << ")" << endl;
    };

    printReport(cout);
    printReport(outFile);
    outFile.close();

    cout << endl << "Report written to grade_report.txt" << endl;
    return 0;
}