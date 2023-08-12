//
// Created by Daniil Slobodeniuk on 2023/07/22.
//

#include "iostream"
#include "vector"
#include "cctype"
#include "climits"

using namespace std;

void display_options();

char take_user_input(char option_letter);

void match_option(char option_letter, vector<int> &elements);

void display_all_digits(const vector<int> &elements);

void add_element(vector<int> &elements);

void calculate_mean(const vector<int> &elements);

void choose_smallest_number(const vector<int> &elements);

void choose_largest_number(const vector<int> &elements);

void check_integer_present(const vector<int> &elements);


void modular_interaction() {
    vector<int> elements;
    char option_letter{};

    do {
        display_options();
        option_letter = take_user_input(option_letter);
        match_option(option_letter, elements);
    } while (option_letter != 'Q');

}

void display_options() {
    cout << "Select one of the options below (case insensitive):\n" << endl;
    cout << "P - Print all the digits" << endl;
    cout << "A - Add a digit" << endl;
    cout << "M - Display the mean of the digits" << endl;
    cout << "S - Show the smallest of the digits" << endl;
    cout << "L - Show the largest of the digits" << endl;
    cout << "E - Check if number is present" << endl;
    cout << "Q - quit the program" << endl;
}

char take_user_input(char option_letter) {
    cin >> option_letter;
    return toupper(option_letter);
}

void match_option(char option_letter, vector<int> &elements) {
    switch (option_letter) {
        case 'P':
            display_all_digits(elements);
            break;
        case 'A':
            add_element(elements);
            break;
        case 'M':
            calculate_mean(elements);
            break;
        case 'S':
            choose_smallest_number(elements);
            break;
        case 'L':
            choose_largest_number(elements);
            break;
        case 'E':
            check_integer_present(elements);
            break;
        case 'Q':
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "You have typed incorrect option: please redo" << endl;
    }
}

void display_all_digits(const vector<int> &elements) {
    if (elements.empty()) {
        cout << "[] - the list is empty" << endl;
    } else {
        for (int ele: elements) {
            cout << "Element: " << ele << endl;
        }
    }
}

void add_element(vector<int> &elements) {
    int num{0};
    cout << "Please, provide an integer: " << endl;
    cin >> num;
    elements.push_back(num);
    cout << "Number: " << num << " has been added" << endl;
}

void calculate_mean(const vector<int> &elements) {
    if (elements.empty()) {
        cout << "Unable to calculate the mean - no data" << endl;
    } else {
        double average{0.0};
        int sum{0};
        for (auto ele: elements) {
            sum += ele;
        }
        average = static_cast<double>(sum) / elements.size();
        cout << "Mean of all elements is: " << average << endl;
    }
}

void choose_smallest_number(const vector<int> &elements) {
    if (elements.empty()) {
        cout << "No elements present -> can't select the smallest" << endl;
    } else {
        int smallest = INT_MAX;
        for (auto ele: elements) {
            smallest = min(smallest, ele);
        }
        cout << "The smallest number is: " << smallest << endl;
    }
}

void choose_largest_number(const vector<int> &elements) {
    if (elements.empty()) {
        cout << "No elements present -> can't select the largest" << endl;
    } else {
        int largest = INT_MIN;
        for (auto ele: elements) {
            largest = max(largest, ele);
        }
        cout << "The largest element is: " << largest << endl;
    }
}

void check_integer_present(const vector<int> &elements) {
    int num{0};
    bool flag = false;
    cout << "Please, input number to check: " << endl;
    cin >> num;
    for (auto ele : elements) {
        if (ele == num) {
            flag = true;
            break;
        }
    }

    string expr = (flag == 1) ? " is present" : " is not in the container";
    cout << "Number " << num << expr << endl;
}
