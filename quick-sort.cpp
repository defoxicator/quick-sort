#include<iostream>

// Get the data
// Divide into two parts in a way that all lower than selected value
// are on the left and all greater are on the right
// Recursively go with it
// Recursive ends when table has less than 2 elements

void display_array(int* array, int array_size) {
    std::cout << "Array: [ ";
    for (int i = 0; i < array_size - 1; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << array[array_size-1] << " ]\n";
}

int divide_array(int* array, int left_index, int right_index) {
    int pivot_index{ 0 };
    int pivot_value{ array[pivot_index] };
    int middle_index{ pivot_index };

    for (int i = pivot_index + 1; i <= right_index; i++) {
        if (array[i] < pivot_value) {
            middle_index = middle_index + 1;
            // std::swap(array[middle_index], array[i]);
            int temp = array[middle_index];
            array[middle_index] = array[i];
            array[i] = temp;
        }
    }
    // std::swap(array[pivot_index], array[middle_index]);
    int temp = array[middle_index];
    array[middle_index] = array[pivot_index];
    array[pivot_index] = temp;

    return middle_index;
}

void quicksort(int* array, int left_index, int right_index) {
    if (right_index - left_index >= 1) {
        int middle_index{ divide_array(array, left_index, right_index) };
        quicksort(array, left_index, middle_index - 1);
        quicksort(array, middle_index + 1, right_index);
    }
}

int main() {
    int array[7]{ 9, 3, 2, 7, 10, 8, 24 };
    int array_size{ sizeof(array) / sizeof(array[0]) };

    display_array(array, array_size);

    quicksort(array, 0, array_size - 1);

    display_array(array, array_size);

    return 0;
}
