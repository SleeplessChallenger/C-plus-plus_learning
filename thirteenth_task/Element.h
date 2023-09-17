//
// Created by Daniil Slobodeniuk on 2023/09/17.
//

#ifndef LEARNINGC___ELEMENT_H
#define LEARNINGC___ELEMENT_H

#include "iostream"

#include "I_Element_Display.h"

class Element : public I_Element_Display {
private:
    int data;
protected:
    static constexpr const int default_data = 4;

public:

    virtual void display_element(std::ostream &os) const override;

    int get_data() const;

    Element();

    Element(int data = default_data);

    virtual ~Element();

};


#endif //LEARNINGC___ELEMENT_H
