#include <stdio.h>

int main() {
    int n;
    
    // Input size
    scanf("%d", &n);
    
    int a[n][n];
    
    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    int isIdentity = 1;
    
    // Check identity matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j && a[i][j] != 1)
                isIdentity = 0;
            if(i != j && a[i][j] != 0)
                isIdentity = 0;
        }
    }
    
    // Output result
    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");
        
    return 0;
}
