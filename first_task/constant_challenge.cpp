//
// Created by Daniil Slobodeniuk on 2023/07/01.
//

#include "iostream"

using namespace std;

void anotherCLeaningService() {
    const double price_per_small_room{25};
    const double price_per_large_room{35};

    const double tax_rate{0.07};

    const int cost_expiration_date{25};

    int number_of_small_rooms{0};
    int number_of_large_rooms{0};
    cout << "Welcome, guys! This is a cleaning service\n" << endl;

    cout << "\nEnter number of small rooms: " << endl;
    cin >> number_of_small_rooms;

    cout << "\nEnter number of large room: " << endl;
    cin >> number_of_large_rooms;

    cout << "Price for small room is " << price_per_small_room << "\nPrice for large room is " << price_per_large_room
         << endl;
    cout << "Cost for small rooms will be "
         << number_of_small_rooms * price_per_small_room + price_per_small_room * number_of_small_rooms * tax_rate
         << endl;
    cout << "Cost for large rooms will be "
         << number_of_large_rooms * price_per_large_room + price_per_large_room * number_of_large_rooms * tax_rate
         << endl;

    cout << "Tax rate is: " << tax_rate << endl;

    cout << "Total cost for all rooms is "
         << (number_of_small_rooms * price_per_small_room + number_of_small_rooms * price_per_small_room * tax_rate) +
            (number_of_large_rooms * price_per_large_room + number_of_large_rooms * price_per_large_room * tax_rate)
         << endl;
    cout << "This result is valid for " << cost_expiration_date << " days";
}