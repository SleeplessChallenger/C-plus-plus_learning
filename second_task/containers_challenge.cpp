//
// Created by Daniil Slobodeniuk on 2023/07/01.
//

#include "iostream"
#include "vector"

using namespace std;

void codeChallengeFunction() {
    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "Size of the vector1 " << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    cout << "Size of the vector1 " << vector2.size() << endl;

//    vector<vector<int>> two_2vector(0, vector<int>(0));
    vector<vector<int>> two_2vector;
    two_2vector.push_back(vector1);
    two_2vector.push_back(vector2);

    cout << two_2vector.at(0).at(0) << endl;
    cout << two_2vector.at(0).at(1) << endl;
    cout << two_2vector.at(1).at(0) << endl;
    cout << two_2vector.at(1).at(1) << endl;

    vector1.at(0) = 1000;

    cout << two_2vector.at(0).at(0) << endl;
    cout << two_2vector.at(0).at(1) << endl;
    cout << two_2vector.at(1).at(0) << endl;
    cout << two_2vector.at(1).at(1) << endl;

}