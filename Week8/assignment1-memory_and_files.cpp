#include <iostream>
#include <fstream>
#include <string>

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int findMax(int* arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max)
            max = *(arr + i);
    }
    return max;
}

void writeNote(std::ofstream& file, const std::string& note) {
    file << note << "\n";
}

void displayNotes(std::ifstream& file) {
    std::string line;
    int lineNum = 1;
    while (std::getline(file, line)) {
        std::cout << "  " << lineNum++ << ". " << line << "\n";
    }
}

void clearNotes() {
    std::ofstream file("notes.txt");
    file.close();
}

void searchNotes(std::ifstream& file, const std::string& keyword) {
    std::string line;
    bool found = false;
    while (std::getline(file, line)) {
        if (line.find(keyword) != std::string::npos) {
            std::cout << "  " << line << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "  No notes found containing: " << keyword << "\n";
}

int main() {
    std::cout << "=== PART 1: MEMORY AND ADDRESSING ===\n\n";

    int age = 25;
    double gpa = 3.75;
    char grade = 'A';

    std::cout << "Variable values and addresses:\n";
    std::cout << "  int    age   = " << age   << "    at address " << &age   << "\n";
    std::cout << "  double gpa   = " << gpa   << "   at address " << &gpa   << "\n";
    std::cout << "  char   grade = '" << grade << "'    at address " << (void*)&grade << "\n";

    std::cout << "\nReference demonstration:\n";
    int& refAge = age;
    std::cout << "  Before: age = " << age << "\n";
    refAge++;
    std::cout << "  After modifying through reference: age = " << age << "\n";

    std::cout << "\nPointer demonstration:\n";
    int* ptr = nullptr;
    ptr = &age;
    std::cout << "  Pointer stores address: " << ptr << "\n";
    std::cout << "  Value at that address:  " << *ptr << "\n";
    if (ptr != nullptr) *ptr = 100;
    std::cout << "  After modifying through pointer: age = " << age << "\n";

    std::cout << "\nSwap function (by reference):\n";
    int x = 10, y = 20;
    std::cout << "  Before: x = " << x << ", y = " << y << "\n";
    swapValues(x, y);
    std::cout << "  After swap: x = " << x << ", y = " << y << "\n";

    std::cout << "\nArray-pointer relationship:\n";
    int arr[] = {5, 12, 7, 42, 3};
    int size = 5;
    std::cout << "  arr[0] = " << arr[0] << "    *(arr + 0) = " << *(arr + 0) << "\n";
    std::cout << "  arr[1] = " << arr[1] << "   *(arr + 1) = " << *(arr + 1) << "\n";
    std::cout << "  Maximum value (via pointer): " << findMax(arr, size) << "\n";

    std::cout << "\n=== PART 2: FILE I/O ===\n\n";

    std::ofstream outFile("notes.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening notes.txt for writing.\n";
        return 1;
    }

    for (int i = 1; i <= 3; i++) {
        std::string note;
        std::cout << "Enter note " << i << ": ";
        std::getline(std::cin, note);
        writeNote(outFile, note);
    }
    outFile.close();
    std::cout << "\nNotes written to notes.txt successfully.\n";

    std::cout << "\nReading notes back from file:\n";
    std::ifstream inFile("notes.txt");
    if (!inFile) {
        std::cerr << "Error opening notes.txt for reading.\n";
        return 1;
    }
    displayNotes(inFile);
    inFile.close();

    return 0;
}