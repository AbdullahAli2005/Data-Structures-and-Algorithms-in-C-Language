#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void freeLinkedList(struct Node *head) {
    struct Node *current = head;
    struct Node *next;

    while (current != NULL) {
        next = current->next; // Save the pointer to the next node
        free(current);        // Free the current node
        current = next;       // Move to the next node
    }
}

int main() {
    // Allocate memory for nodes in the linked list in Heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 5;
    head->next = second;

    // Link second and third nodes
    second->data = 10;
    second->next = third;

    // Link third and fourth nodes
    third->data = 15;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 20;
    fourth->next = NULL;

    // Traversing and displaying the linked list
    linkedListTraversal(head);

    // Freeing the linked list memory
    freeLinkedList(head);

    return 0;
}
