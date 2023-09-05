#include <iostream>

using namespace std;

// Bubble Sort Algorithm
int* bubbleSort(int arr[], int size) 
{
    for (int index = 0; index < size; index++) // Iterating array user created in main,
    {
        for (int j = 0; j < size - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) // if index at arr[j] is greater than next index,
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr; // return sorted array
}

// Printing Sorted Array
void print_arr(int arr[], int size)
{
    for (int index = 0; index < size; index++) // Look at every index of array, 
        cout << arr[index] << " "; // then print array indexes followed by a space
    cout << endl;
}

// Main Code
int main() {
    int size; // Creating int to hold user input for array size
    cin >> size; // User input
   

    // Creating array with user inputs for size (size of array), and the indexes of the array
    int* arr = new int[size]; // allocate dynamic array

    for (int index = 0; index < size; index++)  // iterate array
    {
        cin >> arr[index]; // input for every index of array of size 'size'
    }

    // Call Bubble Sort to sort using algorithm
    int* ans = bubbleSort(arr, size);

    print_arr(ans, size); // prints finished array

}
