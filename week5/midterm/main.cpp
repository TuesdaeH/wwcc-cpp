// Name: Tuesdae Hunter
// Project: Student Tracker Midterm
// Class: C++
// Description: Manage Student Records

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    double grades[5];
    int gradeCount;
};
// Stored grades as a double array instead of single grade so we can enter decimals if needed and up to 5
// Created a struct to hold student information 
// Chose this over a vector because the assignment requires an array
// A char grade can't do math on letters

const int MAX_STUDENTS = 50;
Student students[MAX_STUDENTS];
int studentCount = 0;
// Used global variables to store the students and count of students for easy access throughout the program

void addStudent() {
    // This function adds a new student to the array
    // Uses getline to allow multi word names and cin for ID and grades
    // A for loop stores each grade entered into the grades array
    // gradeCount tracks how many grades were actually entered
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student list is full!" << endl;
        return;
    }

    Student s;
    s.gradeCount = 0;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter student ID: ";
    cin >> s.id;

    int numGrades;
    cout << "How many grades? (max 5): ";
    cin >> numGrades;

    for (int i = 0; i < numGrades && i < 5; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> s.grades[i];
        s.gradeCount++;
    }

    students[studentCount] = s;
    studentCount++;

    cout << "Student added!" << endl;
}

void displayAll() {
    // This function loops through all students and displays their info
    // Uses a nested for loop to add up all grades and calculate the average
    // If no students have been added it lets the user know
    if (studentCount == 0) {
        cout << "No students found." << endl;
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        double total = 0;
        for (int j = 0; j < students[i].gradeCount; j++) {
            total += students[i].grades[j];
        }
        double average = (students[i].gradeCount > 0) ? total / students[i].gradeCount : 0;

        cout << "\nName: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Average Grade: " << average << endl;
    }
}

void searchStudent() {
    // This function searches for a student by name using string .find()
    // Used a bool variable to track if the student was found or not
    // If nothing matches it tells the user the student was not found
    string search;
    cout << "Enter student name to search: ";
    cin.ignore();
    getline(cin, search);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].name.find(search) != string::npos) {
            cout << "\nFound: " << students[i].name << endl;
            cout << "ID: " << students[i].id << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Tracker ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;      
            case 2:
                displayAll();
                break;  
            case 3:
                searchStudent();        
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;  
            default:
                cout << "Invalid choice. Try again." << endl;   
        }
    } while (choice != 4);

    return 0;
}
// Used switch instead of if/else since we're checking the same variable multiple times, cleaner that way
// Main function shows the menu, takes user input, and loops until they pick 4 to quitg++ main.cpp -o main