#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // If the list is empty, the new node becomes the head
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
    

// Function to delete the first node
struct Node* deleteAtFirst(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete the last node
struct Node* deleteAtLast(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        // This was the only node
        head = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node at a specific index
struct Node* deleteAtIndex(struct Node* head, int index) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    if (index == 0) {
        return deleteAtFirst(head);
    }
    struct Node* temp = head;
    for (int i = 0; i < index && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index out of bounds.\n");
        return head;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    return head;
}

// Function to delete a node by value
struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return head;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // If deleting the head node
    }
    free(temp);
    return head;
}

// Function to traverse the doubly linked list
void traverseList(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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
    struct Node *head = NULL;

    // Initiating doubly linked list
    head = appendNode(head, 10);
    head = appendNode(head, 20);
    head = appendNode(head, 30);
    head = appendNode(head, 40);
    head = appendNode(head, 50);
    traverseList(head);

    head = deleteAtFirst(head);
    traverseList(head);

    head = deleteAtLast(head);
    traverseList(head);

    head = deleteAtIndex(head, 1);
    traverseList(head);

    head = deleteByValue(head, 40);
    traverseList(head);

    // Free the memory allocated for the list
    freeMemory(head);

    return 0;
}
