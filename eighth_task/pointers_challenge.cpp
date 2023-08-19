//
// Created by Daniil Slobodeniuk on 2023/08/05.
//


#include "iostream"

using namespace std;

void print_array_elements(const int *const arr, size_t arr_size);

int *apply_all_to_new_array(const int *const arr1, size_t size1, const int *const arr2, size_t size2);

void print_pointers_array() {
    const size_t arr1_size{5};
    const size_t arr2_size{3};

    int arr1[]{1, 2, 3, 4, 5};
    int arr2[]{10, 20, 30};

    cout << "Array1: ";
    print_array_elements(arr1, arr1_size);

    cout << "Array2: ";
    print_array_elements(arr2, arr2_size);

    int *result = apply_all_to_new_array(arr1, arr1_size, arr2, arr2_size);

    const size_t result_size{arr1_size * arr2_size};
    cout << "Result: ";
    print_array_elements(result, result_size);
    cout << endl;

    delete[] result;
}

void print_array_elements(const int *const arr, size_t arr_size) {
    for (size_t i{0}; i < arr_size; i++) {
        cout << "ele: " << arr[i] << "\n";
//        cout << "ele: " << *(arr + i) << "\n";
    }
    cout << endl;
}

int *apply_all_to_new_array(const int *const arr1, const size_t size1, const int *const arr2, const size_t size2) {
    int *result{nullptr};
    result = new int[size1 * size2];

    int position{0};
    for (size_t i{0}; i < size2; i++) {
        for (int j{0}; j < size1; j++) {
            result[position] = arr1[j] * arr2[i];
            position++;
        }
    }

    return result;
}
