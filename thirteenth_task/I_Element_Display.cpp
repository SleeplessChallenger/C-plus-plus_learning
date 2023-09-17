//
// Created by Daniil Slobodeniuk on 2023/09/17.
//

#include "iostream"
#include "I_Element_Display.h"

std::ostream &operator<<(std::ostream &os, const I_Element_Display &obj) {
    obj.display_element(os);
    return os;
}