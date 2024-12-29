#include <stdio.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int array[], int middle, int low, int high) {
    int leftIndex = low, rightIndex = middle + 1, tempIndex = low;
    int tempArray[100]; // Temporary array for merging

    // Merge the two halves into tempArray
    while (leftIndex <= middle && rightIndex <= high) {
        if (array[leftIndex] < array[rightIndex]) {
            tempArray[tempIndex] = array[leftIndex];
            leftIndex++;
        } else {
            tempArray[tempIndex] = array[rightIndex];
            rightIndex++;
        }
        tempIndex++;
    }

    // Copy the remaining elements from the left half
    while (leftIndex <= middle) {
        tempArray[tempIndex] = array[leftIndex];
        leftIndex++;
        tempIndex++;
    }

    // Copy the remaining elements from the right half
    while (rightIndex <= high) {
        tempArray[tempIndex] = array[rightIndex];
        rightIndex++;
        tempIndex++;
    }

    // Copy the sorted elements back to the original array
    for (int i = low; i <= high; i++) {
        array[i] = tempArray[i];
    }
}

void mergeSort(int array[], int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;

        // Sort the left half
        mergeSort(array, low, middle);

        // Sort the right half
        mergeSort(array, middle + 1, high);

        // Merge the two halves
        merge(array, middle, low, high);
    }
}

int main() {
    int array[] = {78, 45, 90, 12, 34, 70, 43, 56, 88, 9};
    int size = 10;
    
    printf("Array before sorting:\n");
    printArray(array, size);

    mergeSort(array, 0, size - 1);

    printf("Array after sorting:\n");
    printArray(array, size);

    return 0;
}
