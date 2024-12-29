#include <stdio.h>

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int* array, int size) {
    int temp;
    for (int pass = 0; pass < size - 1; pass++) { 
        printf("Working on pass number %d\n", pass + 1);
        for (int i = 0; i < size - 1 - pass; i++) { 
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int* array, int size) {
    int temp;
    int isAlreadySorted;
    for (int pass = 0; pass < size - 1; pass++) { 
        printf("Working on pass number %d\n", pass + 1);
        isAlreadySorted = 1; 
        for (int i = 0; i < size - 1 - pass; i++) { 
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                isAlreadySorted = 0; 
            }
        }
        if (isAlreadySorted) {
            return;
        }
    }
}

int main() {
    // int array[] = {78, 45, 90, 12, 34, 70, 43, 56, 88, 9};
    // int size = 10;
    int array[] = {2,4,6,8,10};
    int size = 5;

    printf("Array before sorting:\n");
    printArray(array, size);

    bubbleSort(array, size); 
    bubbleSortAdaptive(array, size); 

    printf("Array after sorting:\n");
    printArray(array, size);

    return 0;
}
