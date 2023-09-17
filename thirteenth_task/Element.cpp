//
// Created by Daniil Slobodeniuk on 2023/09/17.
//

#include "iostream"

#include "Element.h"

void Element::display_element(std::ostream &os) const {
    std::cout << "Element with data: " << data << std::endl;
}

int Element::get_data() const {
    return data;
}

Element::Element(int data)
        : data{data} {

}

Element::Element()
        : data{0} {

}

Element::~Element() {
    std::cout << "Destructor" << std::endl;
}