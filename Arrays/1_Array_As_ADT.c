#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray * a, int totalSize, int usedSize){
    // (*a).total_size = totalSize;
    // (*a).used_size = usedSize;
    // (*a).ptr = (int *)malloc(totalSize * sizeof(int));

    a->total_size = totalSize;
    a->used_size = usedSize;
    a->ptr = (int *)malloc(totalSize * sizeof(int));
}

void show(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setValue(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    
}

int main(){
    struct myArray marks;
    createArray(&marks, 8, 4);
    printf("We are running setValue now\n");
    setValue(&marks);

    printf("We are running show now\n");
    show(&marks);

    free(marks.ptr);

    return 0;
}