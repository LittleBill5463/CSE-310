#include <iostream>

using namespace std;

// Bubble Sort Algorithm
int* bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n; i++) // Iterating array created in main,
    {
        for (int j = 0; j < n - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) // if index at arr[j] is greater than next index,
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr; // return sorted array
}

// Printing Sorted Array
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++) // Look at every index of array, 
        cout << arr[i] << " "; // then print array indexes followed by a space
    cout << endl;
}

// Main Code
int main() {
    int n; // Creating int to hold user input for array size
    cin >> n; // User input
   

    // Creating array with user inputs for n (size of array), and the indexes of the array
    int* arr = new int[n]; // allocate dynamic array

    for (int i = 0; i < n; i++)  // iterate array
    {
        cin >> arr[i]; // input for every index of array of size n
    }

    // Call Bubble Sort to sort using algorithm
    int* ans = bubbleSort(arr, n);

    print_arr(ans, n); // prints finished array

}