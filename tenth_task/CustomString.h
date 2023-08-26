//
// Created by Daniil Slobodeniuk on 2023/08/19.
//

#ifndef LEARNINGC___CUSTOMSTRING_H
#define LEARNINGC___CUSTOMSTRING_H

#include "iostream"

class CustomString {
//    friend CustomString operator+(const CustomString &lhs, const CustomString &rhs);

    friend std::ostream &operator<<(std::ostream &os, const CustomString &rhs);

    friend std::istream &operator>>(std::istream &in, CustomString &rhs);

private:
    char *str;

public:

    char *get_str_pointer() const;

    int get_str_length() const;

    CustomString(); // NoArgs constructor
    CustomString(const char *src); // Default constructor
    CustomString(const CustomString &lhs); // Copy constructor
    CustomString(CustomString &&rhs); // Move constructor
    ~CustomString(); // Destructor

    // assignment
    CustomString &operator=(const CustomString &rhs);

    CustomString &operator=(CustomString &&rhs);

    // member functions

    CustomString operator-() const;

    bool operator==(const CustomString &rhs) const;

    bool operator!=(const CustomString &rhs) const;

    bool operator<(const CustomString &rhs) const;

    bool operator>(const CustomString &rhs) const;

    CustomString operator+(const CustomString &rhs) const;

    CustomString &operator+=(const CustomString &rhs);

    CustomString operator*(int num_times) const;

    CustomString &operator*=(int num_times);

    CustomString &operator++();

    CustomString operator++(int);

};


#endif //LEARNINGC___CUSTOMSTRING_H
