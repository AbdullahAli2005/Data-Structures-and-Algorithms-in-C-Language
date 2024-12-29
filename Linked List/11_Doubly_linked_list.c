#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* prev; // Pointer to the previous node
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the doubly linked list
struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // If the list is empty, the new node becomes the head
    }

    struct Node* temp = head;
    while (temp->next != NULL) { 
        // Traverse to the last node
        temp = temp->next;
    }

    temp->next = newNode; // Link the last node to the new node
    newNode->prev = temp; // Link the new node back to the last node
    return head;
}

// Function to traverse the doubly linked list in forward direction
void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Forward Traversal:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to traverse the doubly linked list in reverse direction
void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward Traversal:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to free the memory allocated for the doubly linked list
void freeMemory(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* next = temp->next; // Store the pointer to the next node
        free(temp);                     // Free the current node
        temp = next;                    // Move to the next node
    }
    printf("Memory freed successfully.\n");
}

int main() {
    struct Node* head = NULL;

    // Initiating doubly linked list
    head = appendNode(head, 10);
    head = appendNode(head, 20);
    head = appendNode(head, 30);
    head = appendNode(head, 40);
    head = appendNode(head, 50);

    // Traverse the list in both directions
    traverseForward(head);
    traverseBackward(head);

    // Free the memory allocated for the list
    freeMemory(head);

    return 0;
}
