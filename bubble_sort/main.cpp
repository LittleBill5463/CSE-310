#include <iostream>
using namespace std;

int* bubbleSort(int arr[], int size) 
{
    for (int index = 0; index < size; index++) 
    {
        for (int j = 0; j < size - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

void print_array(int arr[], int size)
{
    for (int index = 0; index < size; index++) 
        cout << arr[index] << " "; 
    cout << endl;
}

int main() {
    int size; 
    cin >> size; 

    int* arr = new int[size]; 

    for (int index = 0; index < size; index++)  
    {
        cin >> arr[index]; 
    }

    int* ans = bubbleSort(arr, size);

    print_array(ans, size); 

    delete[] arr; 

    return 0;
}
