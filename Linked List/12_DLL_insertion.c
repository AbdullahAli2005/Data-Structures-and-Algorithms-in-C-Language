#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int data;
    struct Node *prev; // Pointer to the previous node
    struct Node *next; // Pointer to the next node
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode; // New node becomes the head
}

// Function to append a node at the end of the doubly linked list; insertAtLast is implemented in it
struct Node *appendNode(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode; // If the list is empty, the new node becomes the head
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next; // Traverse to the last node
    }

    temp->next = newNode; // Link the last node to the new node
    newNode->prev = temp; // Link the new node back to the last node
    return head;
}

// Function to insert a node after a given node
void insertAfterNode(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("The given previous node cannot be NULL.\n");
        return;
    }

    struct Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
    {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

// Function to insert a node before a given node
struct Node *insertBeforeNode(struct Node *head, struct Node *nextNode, int data)
{
    if (nextNode == NULL)
    {
        printf("The given next node cannot be NULL.\n");
        return head;
    }

    struct Node *newNode = createNode(data);
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;

    if (nextNode->prev != NULL)
    {
        nextNode->prev->next = newNode;
    }
    else
    {
        head = newNode; // New node becomes the head
    }

    nextNode->prev = newNode;
    return head;
}

// Function to insert a node at a specific index
struct Node *insertAtIndex(struct Node *head, int index, int data)
{
    if (index < 0)
    {
        printf("Index must be non-negative.\n");
        return head;
    }

    if (index == 0)
    {
        return insertAtBeginning(head, data);
    }

    struct Node *temp = head;
    int i = 0;

    // Traverse to the node at (index - 1) position
    while (temp != NULL && i < index - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Index out of bounds.\n");
        return head;
    }

    // Insert after the (index - 1)th node
    insertAfterNode(temp, data);
    return head;
}

// Function to traverse the doubly linked list in forward direction
void traverseForward(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Forward Traversal:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to traverse the doubly linked list in reverse direction
void traverseBackward(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;

    // Traverse to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Backward Traversal:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to free the memory allocated for the doubly linked list
void freeMemory(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        struct Node *next = temp->next; // Store the pointer to the next node
        free(temp);                     // Free the current node
        temp = next;                    // Move to the next node
    }
    printf("Memory freed successfully.\n");
}

int main()
{
    struct Node *head = NULL;

    // Initiating doubly linked list
    head = insertAtBeginning(head, 10);
    head = appendNode(head, 20);
    head = appendNode(head, 30);
    traverseForward(head);

    insertAfterNode(head, 25);
    traverseForward(head);

    head = insertBeforeNode(head, head->next->next, 15);
    traverseForward(head);

    head = insertAtIndex(head, 0, 5);
    head = insertAtIndex(head, 3, 35);
    head = insertAtIndex(head, 10, 50); // Attempt to insert at out-of-bounds index

    traverseForward(head);
    traverseBackward(head);

    // Free the memory allocated for the list
    freeMemory(head);

    return 0;
}
