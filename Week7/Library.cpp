#include "Library.h"
#include <iostream>
#include <algorithm>

Library::Library(std::string name) : name(name) {}

void Library::addBook(const Book& book) {
    books.push_back(book);
    std::cout << "Book added!\n";
}

void Library::displayAll() const {
    if (books.empty()) {
        std::cout << "No books in catalog.\n";
        return;
    }
    std::cout << "\nCATALOG:\n";
    for (int i = 0; i < books.size(); i++) {
        std::cout << i + 1 << ". ";
        books[i].display();
    }
}

void Library::searchByAuthor(const std::string& authorName) const {
    std::string searchLower = authorName;
    std::transform(searchLower.begin(), searchLower.end(), searchLower.begin(), ::tolower);

    bool found = false;
    std::cout << "\nBooks by " << authorName << ":\n";
    for (const Book& b : books) {
        std::string nameLower = b.getAuthor().getName();
        std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
        if (nameLower.find(searchLower) != std::string::npos) {
            std::cout << "  - \"" << b.getTitle() << "\" (" << b.getPublicationYear() << ")\n";
            found = true;
        }
    }
    if (!found) std::cout << "  No books found for that author.\n";
}

void Library::searchByTitle(const std::string& keyword) const {
    std::string searchLower = keyword;
    std::transform(searchLower.begin(), searchLower.end(), searchLower.begin(), ::tolower);

    bool found = false;
    std::cout << "\nBooks matching \"" << keyword << "\":\n";
    for (const Book& b : books) {
        std::string titleLower = b.getTitle();
        std::transform(titleLower.begin(), titleLower.end(), titleLower.begin(), ::tolower);
        if (titleLower.find(searchLower) != std::string::npos) {
            std::cout << "  - \"" << b.getTitle() << "\" (" << b.getPublicationYear() << ")\n";
            found = true;
        }
    }
    if (!found) std::cout << "  No books found for that title.\n";
}

void Library::showStats() const {
    std::cout << "\nSTATS:\n";
    std::cout << "  Total books in catalog: " << books.size() << "\n";
}