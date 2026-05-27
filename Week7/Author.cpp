#include "Author.h"
#include <iostream>

Author::Author(std::string name, int birthYear) : name(name), birthYear(birthYear) {}

std::string Author::getName() const { return name; }

int Author::getBirthYear() const { return birthYear; }

void Author::display() const {
    std::cout << "Author: " << name << " (born " << birthYear << ")\n";
}