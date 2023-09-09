//
// Created by Daniil Slobodeniuk on 2023/09/03.
//

#include "iostream"

#include "I_PrintablePoly.h"


std::ostream &operator<<(std::ostream &os, const I_PrintablePoly &obj) {
    obj.print_obj(os);
    return os;
}