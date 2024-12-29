#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void circularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

void freeCircularLinkedList(struct Node *head) {
    if (head == NULL) return; // If the list is empty, nothing to free

    struct Node *current = head;
    struct Node *next;

    // Traverse the list and free each node
    do {
        next = current->next; // Save the pointer to the next node
        free(current);        // Free the current node
        current = next;       // Move to the next node
    } while (current != head); // Stop when we loop back to the head
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 8;
    head->next = second;

    // Link second and third nodes
    second->data = 16;
    second->next = third;

    // Link third and fourth nodes
    third->data = 24;
    third->next = fourth;

    // Link fourth back to head to form a circular list
    fourth->data = 32;
    fourth->next = head;

    printf("Circular linked list:\n");
    circularLinkedListTraversal(head);

    // Free the circular linked list
    freeCircularLinkedList(head);
    printf("Memory freed successfully.\n");
    
    return 0;
}
