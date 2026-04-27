#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

// Structure for adjacency list
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Min Heap structure
typedef struct {
    int vertex, dist;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

// Swap heap nodes
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int v, int dist) {
    heap[heapSize].vertex = v;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

// Pop min from heap
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra function
void dijkstra(int n, int source) {
    int dist[MAX];
    
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while (heapSize > 0) {
        HeapNode curr = pop();
        int u = curr.vertex;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

// Main
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // undirected
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}