#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    return q->rear == q->front;
}

int isFull(struct Queue *q)
{
    return q->rear == q->size - 1;
}

void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct Queue *q)
{
    int dequeuedElement = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->front++;
        dequeuedElement = q->arr[q->front];
    }
    return dequeuedElement;
}

struct Queue *createQueue(int size)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int));
    return q;
}

void traverse(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

// Free the queue memory
void freeQueue(struct Queue *q)
{
    free(q->arr);
    free(q);
}

int main()
{
    struct Queue *q = createQueue(10);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    traverse(q);

    printf("Dequeuing element: %d\n", dequeue(q));
    printf("Dequeuing element: %d\n", dequeue(q));
    printf("Dequeuing element: %d\n", dequeue(q));

    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);

    traverse(q);

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(q))
    {
        printf("Queue is full\n");
    }

    // Free the dynamically allocated memory
    freeQueue(q);

    return 0;
}
