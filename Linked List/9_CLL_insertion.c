#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    // Insert node
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node
    p->next = ptr;
    ptr->next = head;
    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

void freeCircularLinkedList(struct Node *head) {
    if (head == NULL) return; // If the list is empty, nothing to free

    struct Node *current = head;
    struct Node *next;

    // Traverse and free each node
    do {
        next = current->next; // Save the next node
        free(current);        // Free the current node
        current = next;       // Move to the next node
    } while (current != head);
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
    head->data = 10;
    head->next = second;

    // Link second and third nodes
    second->data = 18;
    second->next = third;

    // Link third and fourth nodes
    third->data = 20;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 55;
    fourth->next = head;

    printf("Circular linked list before insertions:\n");
    linkedListTraversal(head);

    // Insert at the beginning
    head = insertAtFirst(head, 10);
    printf("\nCircular linked list after inserting 10 at the beginning:\n");
    linkedListTraversal(head);

    // Insert at index 2
    head = insertAtIndex(head, 15, 2);
    printf("\nCircular linked list after inserting 15 at index 2:\n");
    linkedListTraversal(head);

    // Insert at the end
    head = insertAtEnd(head, 20);
    printf("\nCircular linked list after inserting 20 at the end:\n");
    linkedListTraversal(head);

    // Insert after the second node
    head = insertAfterNode(head, second, 25);
    printf("\nCircular linked list after inserting 25 after the second node:\n");
    linkedListTraversal(head);

    // Free the circular linked list
    freeCircularLinkedList(head);
    printf("Memory freed successfully.\n");

    return 0;
}
