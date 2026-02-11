#include <stdio.h>

int main() {
    int m, n;
    
    // Read rows and columns
    scanf("%d %d", &m, &n);
    
    int A[m][n], B[m][n];
    
    // Input first matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    // Input second matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    // Add and print result
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", A[i][j] + B[i][j]);
            if(j < n - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
