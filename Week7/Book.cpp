#include "Book.h"
#include <iostream>

Book::Book(std::string title, int publicationYear, std::string isbn, Author author)
    : title(title), publicationYear(publicationYear), isbn(isbn), author(author) {}

std::string Book::getTitle() const { return title; }

int Book::getPublicationYear() const { return publicationYear; }

std::string Book::getIsbn() const { return isbn; }

Author Book::getAuthor() const { return author; }

void Book::setPublicationYear(int year) {
    if (year <= 0) std::cout << "Invalid year. Must be positive.\n";
    else publicationYear = year;
}

void Book::display() const {
    std::cout << "\"" << title << "\" (" << publicationYear << ")\n";
    std::cout << "   Author: " << author.getName() << " (born " << author.getBirthYear() << ")\n";
    std::cout << "   ISBN: " << isbn << "\n";
}