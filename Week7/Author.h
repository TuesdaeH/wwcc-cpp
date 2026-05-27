#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

class Author {
private:
    std::string name;
    int birthYear;

public:
    Author(std::string name, int birthYear);
    std::string getName() const;
    int getBirthYear() const;
    void display() const;
};

#endif