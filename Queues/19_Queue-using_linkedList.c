#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front; 
    struct Node* rear;  
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL; // Initialize an empty queue
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Enqueue (add element to the rear of the queue)
void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty(q)) {
        // If queue is empty, front and rear point to the new node
        q->front = q->rear = newNode;
    } else {
        // Add the new node at the rear and update the rear pointer
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", val);
}

// Dequeue (remove element from the front of the queue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Retrieve the front node
    struct Node* temp = q->front;
    int dequeuedElement = temp->data;

    // Move front to the next node
    q->front = q->front->next;

    // If the queue is now empty, update rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    // Free the dequeued node and return the value
    free(temp);
    return dequeuedElement;
}

void traverse(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free the memory
void freeQueue(struct Queue* q) {
    struct Node* temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    traverse(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    traverse(q);

    enqueue(q, 40);
    enqueue(q, 50);

    traverse(q);

    // Free the allocated memory
    freeQueue(q);

    return 0;
}
