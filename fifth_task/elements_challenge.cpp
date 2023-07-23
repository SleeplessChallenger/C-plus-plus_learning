//
// Created by Daniil Slobodeniuk on 2023/07/08.
//

#include "iostream"
#include "vector"
#include "climits"

using namespace std;

void sevenChallenge() {
    vector<int> all_elements;
    char option_letter{};
    cout << "\nSelect one of the options from below (case insensitive):" << endl;

    do {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cin >> option_letter;

        switch (option_letter) {
            case 'p':
            case 'P': {
                if (all_elements.empty()) {
                    cout << "[] - the list is empty" << endl;
                } else {
                    for (int ele: all_elements) {
                        cout << "Element: " << ele << endl;
                    }
                }
                break;
            }
            case 'a':
            case 'A': {
                int num{0};
                cout << "Please, enter an integer: " << endl;
                cin >> num;
                all_elements.push_back(num);
                cout << num << " added" << endl;
                break;
            }
            case 'm':
            case 'M': {
                if (all_elements.empty()) {
                    cout << "Unable to calculate the mean - no data" << endl;
                } else {
                    double average{0.0};
                    int sum{0};
                    for (int ele: all_elements) {
                        sum += ele;
                    }

                    average = static_cast<double>(sum) / all_elements.size();
                    cout << "Mean of all numbers is: " << average << endl;
                }
                break;
            }
            case 's':
            case 'S': {
                if (all_elements.empty()) {
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                } else {
                    int smallest = INT_MAX;
                    for (int ele: all_elements) {
                        smallest = min(ele, smallest);
                    }
                    cout << "The smallest number is: " << smallest << endl;
                }
                break;
            }
            case 'l':
            case 'L':
                if (all_elements.empty()) {
                    cout << "Unable to determine the largest number - list is empty" << endl;
                } else {
                    int largest = INT_MIN;
                    for (int ele: all_elements) {
                        largest = max(ele, largest);
                    }
                    cout << "The largest number is: " << largest << endl;
                }
                break;
            case 'q':
            case 'Q': {
                cout << "Goodbye!" << endl;
                break;
            }
            default:
                cout << "You have selected an illegal option, please try again";
        }

    } while (option_letter != 'q' && option_letter != 'Q');
}