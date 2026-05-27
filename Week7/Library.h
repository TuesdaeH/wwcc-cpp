#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"

class Library {
private:
    std::string name;
    std::vector<Book> books;

public:
    Library(std::string name);
    void addBook(const Book& book);
    void displayAll() const;
    void searchByAuthor(const std::string& authorName) const;
    void searchByTitle(const std::string& keyword) const;
    void showStats() const;
};

#endif