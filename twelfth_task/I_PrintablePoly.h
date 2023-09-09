//
// Created by Daniil Slobodeniuk on 2023/09/03.
//

#ifndef LEARNINGC___I_PRINTABLEPOLY_H
#define LEARNINGC___I_PRINTABLEPOLY_H

#include "iostream"

class I_PrintablePoly {
    friend std::ostream &operator<<(std::ostream &os, const I_PrintablePoly &obj);

public:
    virtual void print_obj(std::ostream &os) const = 0;

    virtual ~I_PrintablePoly() = default;
};


#endif //LEARNINGC___I_PRINTABLEPOLY_H
