#include <stdio.h>

#define V 6

// Function for Topological Sort
void topologicalSort(int graph[V][V]) {
    int indegree[V] = {0};
    int queue[V], front = 0, rear = 0;
    int topo[V], index = 0;

    // Calculate indegree of each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) {
                indegree[j]++;
            }
        }
    }

    // Add all nodes with indegree 0 to queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Process queue
    while (front < rear) {
        int node = queue[front++];
        topo[index++] = node;

        for (int i = 0; i < V; i++) {
            if (graph[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Print Topological Order
    printf("Topological Order: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", topo[i]);
    }
}

// Main Function
int main() {
    int graph[V][V] = {
        {0,1,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,0,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };

    topologicalSort(graph);

    return 0;
}