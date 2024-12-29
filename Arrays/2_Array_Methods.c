#include<stdio.h>
 
 
void display(int arr[], int n){
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}
 
int insertion(int arr[], int size, int element, int capacity, int index){
    // code for Insertion
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1; 
}

void deletion(int arr[], int size, int index)
{
    // code for Deletion
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }  
}
 
int main(){
    int arr[100] = {2, 4, 6, 10, 12};
    int size = 5, element = 8, index=3;

    printf("Array Traversel\n");
    display(arr, size); 

    insertion(arr, size, element, 100, index);
    printf("Array Insertion Completed\n");
    size +=1;
    display(arr, size);

    deletion(arr, size, index);
    printf("nth Element Deleted\n");
    size -+1;
    display(arr, size);

    return 0;
}
