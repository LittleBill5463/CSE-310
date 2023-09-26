#include <bits/stdc++.h>
using namespace std;

void merge_two_sorted_arrays(long long int array[], int const left, int const mid, int const right) 
{
    // Sub-array sizes
	int const sub_array_one = mid - left + 1;
	int const sub_array_two = right - mid;

	// Create temp arrays
	long long int *left_array = new long long int[sub_array_one];
	long long int *right_array = new long long int[sub_array_two];

	/* Copy data to temp arrays leftArray[] and rightArray[] */
        // Your code here
        for (int i = 0; i < sub_array_one; i++)
            left_array[i] = array[left + i];
        
        for (int i = 0; i < sub_array_two; i++)
            right_array[i] = array[mid + 1 + i];

    /* Indices of the left, right and merged array*/
        // Your code here
        int i_left = 0;
        int i_right = 0;
        int merged = left;

	/* Merge the temp arrays back into array[left..right] */
        // Your code here
        while (i_left < sub_array_one && i_right < sub_array_two) 
        {
            if (left_array[i_left] <= right_array[i_right]) 
            {
                array[merged] = left_array[i_left];
                i_left++;
            } 
            else   
            {
                array[merged] = right_array[i_right];
                i_right++;
            }

            merged++;
        }

	/* Copy the remaining elements of
	   left[], if there are any */
        // Your code here
        while (i_left < sub_array_one) 
        {
            array[merged] = left_array[i_left];
            i_left++;
            merged++;
        }

	/* Copy the remaining elements of
	   right[], if there are any */
       // Your code here
        while (i_right < sub_array_two) 
        {
            array[merged] = right_array[i_right];
            i_right++;
            merged++;
        }

	// Delete left and right sub-arrays
        delete[] left_array;
        delete[] right_array;
    }

void merge_sort(long long int array[], int const begin, int const end)
{
    /* Recursive calls of merge_sort and merge_two_sorted_arrays */
        // Your code here
        if (begin < end) 
        {
            int mid = begin + (end - begin) / 2;

            // Call Merge_Sort
            merge_sort(array, begin, mid);
            merge_sort(array, mid + 1, end);

            // Merge the two sorted arrays
            merge_two_sorted_arrays(array, begin, mid, end);
        }
	
}