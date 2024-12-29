#include <stdio.h>

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int* array, int size) {
    int currentValue, position;

    for (int currentIndex = 1; currentIndex < size; currentIndex++) {
        currentValue = array[currentIndex]; 
        position = currentIndex - 1;     

        while (position >= 0 && array[position] > currentValue) {
            array[position + 1] = array[position];
            position--;
        }
        array[position + 1] = currentValue;
    }
}

int main() {
    int array[] = {78, 45, 90, 12, 34, 70, 43, 56, 88, 9};
    int size = 10;

    printf("Array before sorting:\n");
    printArray(array, size);

    insertionSort(array, size);

    printf("Array after sorting:\n");
    printArray(array, size);

    return 0;
}
