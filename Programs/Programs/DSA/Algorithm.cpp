#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

// Binary Search
int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid; // Return the index if the target is found
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if the target is not found
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 2, 8, 12, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Linear Search
    int target = 8;
    int linearResult = linearSearch(arr, n, target);
    if (linearResult != -1)
    {
        cout << "Linear Search: Element found at index " << linearResult << endl;
    }
    else
    {
        cout << "Linear Search: Element not found" << endl;
    }

    // Binary Search (Requires sorted array)
    bubbleSort(arr, n); // Sorting the array before performing binary search
    int binaryResult = binarySearch(arr, 0, n - 1, target);
    if (binaryResult != -1)
    {
        cout << "Binary Search: Element found at index " << binaryResult << endl;
    }
    else
    {
        cout << "Binary Search: Element not found" << endl;
    }

    // Bubble Sort
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
