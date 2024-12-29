#include <stdio.h>
#include <stdlib.h>

struct Deque {
    int size;
    int front;
    int rear;
    int *arr;
};

struct Deque* createDeque(int size) {
    struct Deque *dq = (struct Deque *)malloc(sizeof(struct Deque));
    dq->size = size;
    dq->front = -1;
    dq->rear = -1;
    dq->arr = (int *)malloc(size * sizeof(int));
    return dq;
}

int isEmpty(struct Deque *dq) {
    return dq->front == -1;
}

int isFull(struct Deque *dq) {
    return ((dq->rear + 1) % dq->size == dq->front);
}

// Insert element at the front
void enqueueFront(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + dq->size) % dq->size;
    }
    dq->arr[dq->front] = value;
    printf("Inserted %d at front\n", value);
}

// Insert element at the rear
void enqueueRear(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % dq->size;
    }
    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear\n", value);
}

// Remove element from the front
int dequeueFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;  // Reset deque
    } else {
        dq->front = (dq->front + 1) % dq->size;
    }
    return value;
}

// Remove element from the rear
int dequeueRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;  // Reset deque
    } else {
        dq->rear = (dq->rear - 1 + dq->size) % dq->size;
    }
    return value;
}

void traverse(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    do {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % dq->size;
    } while (i != (dq->rear + 1) % dq->size);
    printf("\n");
}

// Free the deque memory
void freeDeque(struct Deque *dq) {
    free(dq->arr);
    free(dq);
}

int main() {
    struct Deque *dq = createDeque(5);

    enqueueRear(dq, 10);
    enqueueRear(dq, 20);
    enqueueFront(dq, 5);
    enqueueFront(dq, 1);
    traverse(dq);

    printf("Dequeued from front: %d\n", dequeueFront(dq));
    printf("Dequeued from rear: %d\n", dequeueRear(dq));

    enqueueRear(dq, 25);
    enqueueFront(dq, 2);
    traverse(dq);

    if (isEmpty(dq)) {
        printf("Deque is empty\n");
    }
    if (isFull(dq)) {
        printf("Deque is full\n");
    }

    freeDeque(dq);
    return 0;
}
