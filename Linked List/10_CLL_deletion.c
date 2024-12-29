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

struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) return NULL; // Empty list

    struct Node* temp = head;
    struct Node* p = head;

    // Find the last node
    while (p->next != head) {
        p = p->next;
    }

    // Update the last node to point to the new head
    p->next = head->next;
    head = head->next;

    free(temp); // Free the old head
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index) {
    if (head == NULL || index < 0) return head; // Handle invalid cases

    if (index == 0) {
        return deleteFirst(head); // Reuse `deleteFirst` for index 0
    }

    struct Node* p = head;
    struct Node* q;

    // Traverse to the node just before the target node
    for (int i = 0; i < index - 1; i++) {
        p = p->next;
        if (p->next == head) return head; // Index out of bounds
    }

    q = p->next;        
    p->next = q->next;  
    free(q);           

    return head;
}

struct Node* deleteLast(struct Node* head) {
    if (head == NULL) return NULL; // Empty list

    // Single node case
    if (head->next == head) { 
        free(head);
        return NULL;
    }

    struct Node* p = head;
    struct Node* q;

    // Traverse to the second last node
    while (p->next->next != head) {
        p = p->next;
    }

    q = p->next;  // Last node
    p->next = head; // Update second last node to point to head
    free(q);       // Free the last node

    return head;
}

struct Node* deleteGivenValue(struct Node* head, int value) {
    if (head == NULL) return NULL; // Empty list

    if (head->data == value) { // Value is in the head node
        return deleteFirst(head);
    }

    struct Node* p = head;
    struct Node* q;

    // Traverse to find the node with the given value
    while (p->next != head && p->next->data != value) {
        p = p->next;
    }

    if (p->next->data == value) { // Node with the value found
        q = p->next;
        p->next = q->next;
        free(q);
    }

    return head;
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

int main() {
    struct Node *head, *second, *third, *fourth, *fifth, *sixth;

    // Allocate memory for nodes in the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    // Link the nodes to form a circular linked list
    head->data = 8;
    head->next = second;
    second->data = 16;
    second->next = third;
    third->data = 24;
    third->next = fourth;
    fourth->data = 32;
    fourth->next = fifth;
    fifth->data = 40;
    fifth->next = sixth;
    sixth->data = 48;
    sixth->next = head;

    printf("Original Circular Linked List:\n");
    circularLinkedListTraversal(head);

    // Perform deletions
    head = deleteFirst(head);
    printf("\nAfter deleting first node:\n");
    circularLinkedListTraversal(head);

    head = deleteAtIndex(head, 1);
    printf("\nAfter deleting node at index 1:\n");
    circularLinkedListTraversal(head);

    head = deleteLast(head);
    printf("\nAfter deleting last node:\n");
    circularLinkedListTraversal(head);

    head = deleteGivenValue(head, 16);
    printf("\nAfter deleting node with value 16:\n");
    circularLinkedListTraversal(head);

    // Free remaining nodes
    freeCircularLinkedList(head);
    printf("\nMemory freed successfully.\n");

    return 0;
}
