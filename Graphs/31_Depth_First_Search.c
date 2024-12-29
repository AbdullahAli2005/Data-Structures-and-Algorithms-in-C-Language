#include <stdio.h>

#define MAX 100 // Maximum number of nodes

// Function for DFS traversal
void DFS(int graph[MAX][MAX], int visited[], int node, int n) {
    // Mark the current node as visited
    visited[node] = 1;
    printf("%d ", node);

    // Recursively visit all unvisited neighbors
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) { // Check adjacency and visited status
            DFS(graph, visited, i, n);
        }
    }
}

int main() {
    int n; // Number of nodes in the graph
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int graph[MAX][MAX]; // Adjacency matrix representation of the graph
    int visited[MAX] = {0}; // Array to track visited nodes (initialized to 0)

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(graph, visited, start, n);
    printf("\n");

    return 0;
}
