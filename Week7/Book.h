#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"

class Book {
private:
    std::string title;
    int publicationYear;
    std::string isbn;
    Author author;

public:
    Book(std::string title, int publicationYear, std::string isbn, Author author);
    std::string getTitle() const;
    int getPublicationYear() const;
    std::string getIsbn() const;
    Author getAuthor() const;
    void setPublicationYear(int year);
    void display() const;
};

#endif