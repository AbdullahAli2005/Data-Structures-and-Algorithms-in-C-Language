#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

// Initialize the stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push an element onto the stack
void push(struct Stack* stack, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
        return;
    }
    newNode->data = val;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

// Peek at a specific position in the stack
int peek(struct Stack* stack, int position) {
    struct Node* current = stack->top;
    int index = 0;
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    printf("Value at position %d from the top is: %d\n", position, current->data);
    return current->data;
}

// Get the top element of the stack
int stackTop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty. No top element.\n");
        return -1;
    }
    printf("The top value of the stack is: %d\n", stack->top->data);
    return stack->top->data;
}

// Get the bottom element of the stack
int stackBottom(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty. No bottom element.\n");
        return -1;
    }
    struct Node* current = stack->top;
    while (current->next != NULL) {
        current = current->next;
    }
    printf("The bottom value of the stack is: %d\n", current->data);
    return current->data;
}

// Traverse and display the stack
void traverseStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the stack
void freeStack(struct Stack* stack) {
    struct Node* current = stack->top;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

int main() {
    struct Stack* stack = createStack();
    printf("Stack has been created successfully\n");

    printf("Before pushing, Empty: %d\n", isEmpty(stack));

    push(stack, 12);
    push(stack, 24);
    push(stack, 76);
    push(stack, 88);
    push(stack, 45);
    push(stack, 63);
    push(stack, 108);
    push(stack, 37);
    push(stack, 99);
    push(stack, 23);

    traverseStack(stack);

    printf("Popped %d from the stack\n", pop(stack));
    printf("Popped %d from the stack\n", pop(stack));
    printf("Popped %d from the stack\n", pop(stack));

    traverseStack(stack);

    peek(stack, 4);
    peek(stack, 8);

    stackTop(stack);
    stackBottom(stack);

    freeStack(stack);
    printf("Memory Freed\n");

    return 0;
}
 

// FUNCTION	    TIME COMPLEXITY
// isEmpty	         O(1)
// isFull	         O(1)
// push              O(1)
// pop	             O(1)
// peek	             O(n) 
// stackTop          O(1)
// stackBottom	     O(1)
// traverseStack	 O(n)