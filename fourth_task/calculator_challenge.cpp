//
// Created by Daniil Slobodeniuk on 2023/07/07.
//

#include "iostream"

using namespace std;

void shippingCalculator() {
    int length{}, width{}, height{};
    double base_cost{2.50};

    const int tier1_threshold{100}; // volume
    const int tier2_threshold{500}; // volume

    int max_dimension_length{10}; // inches

    double tier1_surcharge{0.10}; // 10% extra
    double tier2_surcharge{0.25}; // 25% surcharge

    // All dimension must be 10 inches or fewer

    int package_volume{0};

    cout << "Welcome to the package cost calculator" << endl;
    cout << "Enter length, width, height of the package separated by spaces: ";
    cin >> length >> width >> height;

    if (length > max_dimension_length || width > max_dimension_length || height > max_dimension_length) {
        cout << "Sorry, package rejected as dimensions exceeded and a ver very super duper"
                "mega long very long string with some !"
             << endl;
    } else {
        double package_cost{0};
        package_volume = length * width * height;
        package_cost = base_cost;

        if (package_volume > tier2_threshold) {
            package_cost += package_cost * tier2_surcharge;
        } else if (package_volume > tier1_threshold) {
            package_cost += package_cost * tier1_surcharge;
        }

        cout << "The volume of your package is: " << package_volume << endl;
        cout << "Your package will cost $" << package_cost << " to ship" << endl;
    }

    cout << "Hello world" << endl;
}