//
// Created by Daniil Slobodeniuk on 2023/07/15.
//

#include "iostream"
#include "string"

using namespace std;

void cipherChallenge() {
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMONPQRSTUVWXYZ *"};
    string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr* "};
    string input;
    cout << "Please, input string to encrypt: \n";

    getline(cin, input);
    // another way: string output {}. And not use at(), but +=. Below you can observe it
    string output(input.length(), 'A');

    cout << "Encrypting a message" << endl;
    for (size_t i{0}; i < input.length(); i++) {
        char letter = input.at(i);
        size_t index_in_alphabet = alphabet.find(letter);
        if (index_in_alphabet == string::npos) {
            cout << "Letter is not found. Skip" << endl;
            output.at(i) = input.at(i);
        } else {
            cout << "Letter: " << letter << " has been found" << endl;
            char letter_in_key = key.at(index_in_alphabet);
            cout << "Letter: " << letter << " will be encrypted with: " << letter_in_key << endl;
            output.at(i) = letter_in_key;
        }
    }

    cout << "Encrypted message is: " << output << endl;

    string decrypted{};
    for (size_t i{0}; i < output.length(); i++) {
        char letter = output.at(i);
        size_t index_in_alphabet = key.find(letter);
        if (index_in_alphabet == string::npos) {
            decrypted += letter;
        } else {
            char letter_in_key = alphabet.at(index_in_alphabet);
            decrypted += letter_in_key;
        }
    }

    cout << "Decrypted message: " << decrypted << endl;
}