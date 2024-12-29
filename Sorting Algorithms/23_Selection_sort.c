#include <stdio.h>

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void selectionSort(int* array, int size) {
    int minIndex, temp;
    printf("Running Selection Sort...\n");
    
    for (int currentPass = 0; currentPass < size - 1; currentPass++) {
        minIndex = currentPass;
        
        // Loop to find the smallest element in the unsorted portion
        for (int i = currentPass + 1; i < size; i++) {
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        
        // Swap the smallest element with the first unsorted element
        temp = array[currentPass];
        array[currentPass] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main() {
    int array[] = {78, 45, 90, 12, 34, 70, 43, 56, 88, 9};
    int size = 10;

    printf("Array before sorting:\n");
    printArray(array, size);

    selectionSort(array, size);

    printf("Array after sorting:\n");
    printArray(array, size);

    return 0;
}
