#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
int dfs(int node, int parent, int n, int adj[MAX][MAX]) {

    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {

            // If not visited → go deeper
            if (!visited[i]) {
                if (dfs(i, node, n, adj))
                    return 1;
            }
            // If visited and NOT parent → cycle found
            else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

// Function to check cycle
int hasCycle(int n, int adj[MAX][MAX]) {

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n, adj))
                return 1;
        }
    }

    return 0;
}

int main() {
    int n, adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    if (hasCycle(n, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}