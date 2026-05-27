#include <iostream>
#include <string>
#include "Library.h"

int main() {
    Library library("Central City Library");
    int choice;

    std::cout << "LIBRARY MANAGEMENT SYSTEM\n";
    std::cout << "--------------------------\n";
    std::cout << "Library: Central City Library\n";

    do {
        std::cout << "\n1. Add Book\n";
        std::cout << "2. Display All Books\n";
        std::cout << "3. Search by Author\n";
        std::cout << "4. Search by Title\n";
        std::cout << "5. Show Stats\n";
        std::cout << "6. Exit\n";
        std::cout << "\nEnter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string title, isbn, authorName;
            int pubYear, birthYear;

            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter publication year: ";
            std::cin >> pubYear;
            std::cin.ignore();
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            std::cout << "Enter author name: ";
            std::getline(std::cin, authorName);
            std::cout << "Enter author birth year: ";
            std::cin >> birthYear;
            std::cin.ignore();

            Author author(authorName, birthYear);
            Book book(title, pubYear, isbn, author);
            library.addBook(book);

        } else if (choice == 2) {
            library.displayAll();

        } else if (choice == 3) {
            std::string authorName;
            std::cout << "Search by author: ";
            std::getline(std::cin, authorName);
            library.searchByAuthor(authorName);

        } else if (choice == 4) {
            std::string keyword;
            std::cout << "Search by title: ";
            std::getline(std::cin, keyword);
            library.searchByTitle(keyword);

        } else if (choice == 5) {
            library.showStats();

        } else if (choice != 6) {
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    std::cout << "Goodbye!\n";
    return 0;
}