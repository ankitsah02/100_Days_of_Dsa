#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int cost[MAX][MAX];

    // Initialize matrix with large value
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cost[i][j] = INT_MAX;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w; // undirected
    }

    int visited[MAX] = {0};
    int mincost = 0;

    visited[1] = 1; // start from node 1

    // MST will have n-1 edges
    for(int edge = 1; edge < n; edge++) {
        int min = INT_MAX;
        int a = -1, b = -1;

        for(int i = 1; i <= n; i++) {
            if(visited[i]) {
                for(int j = 1; j <= n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(a != -1 && b != -1) {
            visited[b] = 1;
            mincost += min;
        }
    }

    printf("%d\n", mincost);

    return 0;
}