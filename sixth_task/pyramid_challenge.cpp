//
// Created by Daniil Slobodeniuk on 2023/07/16.
//

#include "iostream"
#include "string"

using namespace std;

string reverse_string(string s) {
    int i{0};
    int j{static_cast<int>(s.size() - 1)};

    while (i <= j) {
        char left = s.at(i);
        char right = s.at(j);
        s.at(i) = right;
        s.at(j) = left;

        i++;
        j--;
    }

    return s;
}

void showPyramidString() {
    string pyramid{};
    string prev_letters{};
    string curr_letters{};
    cout << "Welcome to the string pyramid. Enter you string without whitespaces:\n" << endl;
    cin >> pyramid;

    int pyramid_symbols = static_cast<int>(pyramid.length());
    int position{0};

    /*
     * keep previous row with a new character, but without repeating characters from prev row - 1
     * ABC: 2nd row is ABA -> 3 rd row will have ABC + BA as B is the new character for that row and A is old - exclude
     */

    for (int i{0}; i < pyramid.length(); i++) {
        char letter = pyramid.at(i);
        curr_letters += letter;
        string reversed_string = reverse_string(prev_letters);

        int spaces = pyramid_symbols - position;
        while (spaces > 0) {
            cout << " ";
            spaces--;
        }
        cout << curr_letters << reversed_string << endl;
        prev_letters += letter;
        position++;
    }
}