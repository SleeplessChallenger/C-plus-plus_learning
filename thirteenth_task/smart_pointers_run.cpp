//
// Created by Daniil Slobodeniuk on 2023/09/17.
//
#include "vector"
#include "memory"

#include "Element.h"

int num_elements{0};

std::unique_ptr<std::vector<std::shared_ptr<Element>>> make();

void fill_vector(std::vector<std::shared_ptr<Element>> &container, int num);

void display_vector(const std::vector<std::shared_ptr<Element>> &container);


void run_pointers() {
    std::unique_ptr<std::vector<std::shared_ptr<Element>>> container_pointer;
    container_pointer = make();

    std::cout << "How many elements in the container do you want?";
    std::cin >> num_elements;

    fill_vector(*container_pointer, num_elements);
    display_vector(*container_pointer);
}


std::unique_ptr<std::vector<std::shared_ptr<Element>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Element>>>();
}

void fill_vector(std::vector<std::shared_ptr<Element>> &container, int num) {
    int idx = 0;
    while (idx < num) {
        int currNum = 0;
        std::cout << "Type number you want to insert in Element: ";
        std::cin >> currNum;
        std::shared_ptr<Element> ptr = std::make_shared<Element>(currNum);
        container.push_back(ptr);
        idx++;
    }
}

void display_vector(const std::vector<std::shared_ptr<Element>> &container) {
    std::cout << "Start showing numbers from container" << std::endl;

    // can skip & as it is shared pointer, but for efficiency - use reference
    for (const std::shared_ptr<Element> &ele: container) {
        std::cout << *ele << std::endl;
        std::cout << ele->get_data() << std::endl;
    }
}