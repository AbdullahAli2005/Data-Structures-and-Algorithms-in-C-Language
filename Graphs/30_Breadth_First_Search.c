#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// BFS function
void BFS(int graph[][5], int start, int n) {
    int visited[n]; // Array to track visited nodes
    for (int i = 0; i < n; i++)
        visited[i] = 0; // Initialize all nodes as not visited

    struct Queue* queue = createQueue(n); // Create a queue for BFS
    visited[start] = 1; // Mark the starting node as visited
    enqueue(queue, start); // Add the starting node to the queue

    printf("BFS Traversal: ");
    while (!isEmpty(queue)) {
        int current = dequeue(queue); // Dequeue a node
        printf("%d ", current);       // Print the current node

        // Visit all unvisited adjacent nodes
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) { // If there is an edge and the node is unvisited
                visited[i] = 1;   // Mark the node as visited
                enqueue(queue, i); // Add the node to the queue
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Example graph represented as an adjacency matrix
    // 0 - 1 - 2
    // |   | 
    // 3   4
    int graph[5][5] = {
        {0, 1, 0, 1, 0}, // Connections for node 0
        {1, 0, 1, 0, 1}, // Connections for node 1
        {0, 1, 0, 0, 0}, // Connections for node 2
        {1, 0, 0, 0, 0}, // Connections for node 3
        {0, 1, 0, 0, 0}  // Connections for node 4
    };

    int startNode = 0; // Starting node for BFS
    BFS(graph, startNode, 5);

    return 0;
}
