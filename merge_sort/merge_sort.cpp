#include <bits/stdc++.h>
using namespace std;

void merge_two_sorted_arrays(long long int array[], int const left, int const mid, int const right) {
    // Sub-array sizes
    int const sub_array_one = mid - left + 1;
    int const sub_array_two = right - mid;

    // Create temp arrays
    long long int *left_array = new long long int[sub_array_one];
    long long int *right_array = new long long int[sub_array_two];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < sub_array_one; i++)
        left_array[i] = array[left + i];
    for (int j = 0; j < sub_array_two; j++)
        right_array[j] = array[mid + 1 + j];

    // Initial indices of the left, right and merged array
    int i_left = 0, i_right = 0;
    int index_of_merged_array = left;

    // Merge the temp arrays back into array[left..right]
    while (i_left < sub_array_one && i_right < sub_array_two) {
        if (left_array[i_left] <= right_array[i_right]) {
            array[index_of_merged_array] = left_array[i_left];
            i_left++;
        } else {
            array[index_of_merged_array] = right_array[i_right];
            i_right++;
        }
        index_of_merged_array++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i_left < sub_array_one) {
        array[index_of_merged_array] = left_array[i_left];
        i_left++;
        index_of_merged_array++;
    }

    // Copy the remaining elements of right[], if there are any
    while (i_right < sub_array_two) {
        array[index_of_merged_array] = right_array[i_right];
        i_right++;
        index_of_merged_array++;
    }

    // Delete left and right sub-arrays
    delete[] left_array;
    delete[] right_array;
}

void merge_sort(long long int array[], int const begin, int const end) {
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    merge_two_sorted_arrays(array, begin, mid, end);
}
