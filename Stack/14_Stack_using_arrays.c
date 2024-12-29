#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Push an element onto the stack
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Pop an element from the stack
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *sp, int i)
{
    int arrayInd = sp->top - i + 1; // Calculate the index of the stack element
    if (arrayInd < 0 || arrayInd > sp->top)
    {
        printf("Not a valid position for the stack\n");
        return -1; 
    }
    else
    {
        int value = sp->arr[arrayInd];
        printf("Value at position %d from the top is: %d\n", i, value);
        return sp->arr[arrayInd]; // Return the value at the calculated index
    }
}

int stackTop(struct stack* sp) {
    if (sp->top == -1) {
        printf("The stack is empty. No top element.\n");
        return -1;
    }
    int topValue = sp->arr[sp->top];
    printf("The top value of the stack is: %d\n", topValue);
    return topValue;
}

int stackBottom(struct stack* sp) {
    if (sp->top == -1) {
        printf("The stack is empty. No bottom element.\n");
        return -1;
    }
    int bottomValue = sp->arr[0];
    printf("The bottom value of the stack is: %d\n", bottomValue);
    return bottomValue;
}


// Traverse and display the stack
void traverseStack(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    push(sp, 12);
    push(sp, 24);
    push(sp, 76);
    push(sp, 88);
    push(sp, 45);
    push(sp, 63);
    push(sp, 108);
    push(sp, 37);
    push(sp, 99);
    push(sp, 23);
    push(sp, 46); // Stack Overflow

    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));

    traverseStack(sp);

    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!

    traverseStack(sp);

    peek(sp, 4);
    peek(sp, 8);

    stackTop(sp);   
    stackBottom(sp);

    // Free allocated memory
    free(sp->arr);
    free(sp);
    printf("Memory Freed");

    return 0;
}


// FUNCTION	    TIME COMPLEXITY
// isEmpty	        O(1)
// isFull	        O(1)
// push             O(1)
// pop	            O(1)
// peek	            O(n)
// stackTop         O(1)
// stackBottom	    O(1)
// traverseStack	O(n)