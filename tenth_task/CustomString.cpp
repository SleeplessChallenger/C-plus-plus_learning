//
// Created by Daniil Slobodeniuk on 2023/08/19.
//

#include "iostream"
#include "cstring"

#include "CustomString.h"

/*
 *  CustomString cs1 {"Some String"};
    cs1 = cs1 + CustomString {"OLOLO"};
    // Move assignment will be called after concatenation

 *  CustomString cs1 {"Some String"};
    cs1 = -cs1;
    // Move assignment will be called after string will be lowered

 *  CustomString cs1 {"Some String"};
    cs1 += CustomString {"Cool"};
    // After concat Move assignment will be called inside operator+=
    // Then temp object in assignment operator will be destructed. Then Cool obj will be destroyed

 *  CustomString cs1 {"Some String"};
    CustomString cs2 {"Another String"};
    cs1  = cs1 * 4;
    // After overloaded + will be called, Move assignment will be triggered. And after that temp variable,
    // which held value for multiplied string, will be deleted
 */

char *CustomString::get_str_pointer() const {
    return str;
}

int CustomString::get_str_length() const {
    return std::strlen(str);
}

CustomString::CustomString()
        : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

CustomString::CustomString(const char *src)
        : str{nullptr} {
    if (src == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(src) + 1];
        std::strcpy(str, src);
    }
}

CustomString::CustomString(const CustomString &lhs)
        : str{nullptr} {
    str = new char[std::strlen(lhs.str) + 1];
    std::strcpy(str, lhs.str);
}

CustomString::CustomString(CustomString &&rhs)
        : str{rhs.str} {
    rhs.str = nullptr;
}

CustomString::~CustomString() {
    delete[] str;
}

// Copy assignment
CustomString &CustomString::operator=(const CustomString &rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment
CustomString &CustomString::operator=(CustomString &&rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// make lowercase
/**
 *
 * @return returns an object, not a reference. As the second one will point to a stack
 * Hence copy of the object will be created
 */
CustomString CustomString::operator-() const {
    char *buffer = new char[std::strlen(str) + 1];
    std::strcpy(buffer, str);

    for (size_t i = 0; i < std::strlen(buffer); i++)
        buffer[i] = std::tolower(buffer[i]);

    CustomString new_obj{buffer};
    delete[] buffer;
    return new_obj;
}

bool CustomString::operator==(const CustomString &rhs) const {
    return (std::strcmp(this->str, rhs.str) == 0);
}

bool CustomString::operator!=(const CustomString &rhs) const {
    return (std::strcmp(this->str, rhs.str) != 0);
}

bool CustomString::operator<(const CustomString &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

bool CustomString::operator>(const CustomString &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

/**
 * @return Also returns object which copy will be made. We can't return reference to
 * the stack memory
 */
CustomString CustomString::operator+(const CustomString &rhs) const {
    char *buffer = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buffer, str);
    std::strcat(buffer, rhs.str);

    CustomString new_obj{buffer};
    delete[] buffer;
    return new_obj;
}

/**
 * This will use overloaded concatenation operator if implemented as member function.
 * In my case I have to do the work as it is moved to global function
 */
CustomString &CustomString::operator+=(const CustomString &rhs) {
    *this = *this + rhs;

    /* Below is an example how to do without overloaded + operator
    char *buffer = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buffer, str);
    std::strcat(buffer, rhs.str);

    CustomString cs {buffer};
    delete[] buffer;

    *this = cs;
    */

    return *this;
/*
 * CustomObject obj {"Some String"};
 * obj += CustomObject {"New"};
 */
}


CustomString CustomString::operator*(int num_size) const {
    char *buffer = new char[std::strlen(str) * num_size + 1];
    std::strcpy(buffer, str);
    for (int i = 0; i <= num_size - 1; i++) {
        std::strcat(buffer, str);
    }

    CustomString new_obj{buffer};
    delete[] buffer;

    /*
    CustomString new_obj;
    // because it is called on the object already and *this will refer to this object
    for (int i = 0; i <= num_size - 1; i++)
        new_obj = new_obj + *this;
    */

    return new_obj;
}

CustomString &CustomString::operator*=(int num_times) {
    *this = *this * num_times;
    return *this;
/*
 * CustomObject obj {"Some String"};
 * obj *= 4;
 */
}

CustomString &CustomString::operator++() {
    for (int i = 0; i < std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
    return *this;
}

CustomString CustomString::operator++(int) {
    CustomString obj{*this}; // Copy constructor will be called
    operator++();
    return obj;
}

// friend functions

/* Example of + by friend func
CustomString operator+(const CustomString &lhs, const CustomString &rhs) {
    char *buffer = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buffer, lhs.str);
    std::strstr(buffer, rhs.str);

    CustomString new_obj{buffer};
    delete[] buffer;
    return new_obj;
}
*/

std::ostream &operator<<(std::ostream &os, const CustomString &rhs) {
    os << "String is: " << rhs.str;
    return os;
}

std::istream &operator>>(std::istream &in, CustomString &rhs) {
    char *buffer = new char[std::strlen(rhs.str) + 1];
    in >> buffer;
    CustomString new_obj{buffer};
    delete[] buffer;
    return in;
}
