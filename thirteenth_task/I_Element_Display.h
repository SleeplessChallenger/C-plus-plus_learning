//
// Created by Daniil Slobodeniuk on 2023/09/17.
//

#ifndef LEARNINGC___I_ELEMENT_DISPLAY_H
#define LEARNINGC___I_ELEMENT_DISPLAY_H

#include "iostream"

class I_Element_Display {
    friend std::ostream &operator<<(std::ostream &os, const I_Element_Display &obj);

public:

    virtual void display_element(std::ostream &os) const = 0;

    virtual ~I_Element_Display() = default;

};


#endif //LEARNINGC___I_ELEMENT_DISPLAY_H
