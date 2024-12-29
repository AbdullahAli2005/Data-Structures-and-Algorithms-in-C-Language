#include <stdio.h>

int binarySearch(int arr[], int size, int element) {
    int low, mid, high;
    low = 0;
    high = size - 1;

    // Keep searching until low <= high
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == element) {
            return mid; // Element found
        }
        if (arr[mid] < element) {
            low = mid + 1; // Move to the right subarray
        } else {
            high = mid - 1; // Move to the left subarray
        }
    }
    return -1; // Element not found
}

int main() {
    // Array must be sorted for binary search
    int arr[] = {12, 24, 35, 48, 55, 78, 99};
    int size = sizeof(arr) / sizeof(int);
    int element = 99; // Element to search for
    int searchIndex = binarySearch(arr, size, element);

    if (searchIndex != -1) {
        printf("The element %d was found at index %d.\n", element, searchIndex);
    } else {
        printf("The element %d was not found in the array.\n", element);
    }

    return 0;
}
