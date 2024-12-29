#include<stdio.h>

int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int arr[] = {25, 34, 56, 77, 98, 11, 33, 55};
    int size = sizeof(arr) / sizeof(int);
    int element = 12;
    int searchIndex = linearSearch(arr, size, element);

    if (searchIndex != -1) {
        printf("The element %d was found at index %d.\n", element, searchIndex);
    } else {
        printf("The element %d was not found in the array.\n", element);
    }

    return 0;
}
