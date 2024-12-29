#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int size;
    int front;
    int rear;
    int *arr;
};

struct CircularQueue* createQueue(int size) {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->arr = (int*)malloc(size * sizeof(int));
    return queue;
}

int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % q->size == q->front;
}

void enqueue(struct CircularQueue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) q->front = 0;  // First element
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        printf("Enqueued: %d\n", val);
    }
}

int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int dequeuedValue = q->arr[q->front];
        if (q->front == q->rear) {
            // Reset to empty queue
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size;
        }
        return dequeuedValue;
    }
}

void traverse(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        do {
            printf("%d ", q->arr[i]);
            i = (i + 1) % q->size;
        } while (i != (q->rear + 1) % q->size);
        printf("\n");
    }
}

void freeQueue(struct CircularQueue* q) {
    free(q->arr);
    free(q);
}

int main() {
    struct CircularQueue* q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    traverse(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    traverse(q);

    enqueue(q, 50);
    enqueue(q, 60);

    traverse(q);

    enqueue(q, 70); 
    enqueue(q, 80); // Queue is full

    traverse(q);

    freeQueue(q);

    return 0;
}
