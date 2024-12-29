#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* sp) {
    if (sp->top == -1) {
        return -1; // Return -1 when stack is empty
    }
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack* ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch) {
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

char* infixToPostfix(char* infix) {
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 20; // Increase size to accommodate larger expressions
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    char *postfix = (char *) malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition 

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        } else {
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp))) {
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
            i++;
        }
    }

    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    // Free stack memory
    free(sp->arr);
    free(sp);

    return postfix;
}

int main() {
    char *infix = "a-b*m+n/k";
    char *postfix = infixToPostfix(infix);

    printf("Postfix is: %s\n", postfix);

    // Free postfix memory
    free(postfix);

    return 0;
}
