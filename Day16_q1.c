#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Frequency count
    for(int i = 0; i < n; i++) {
        int count = 1;

        // Skip if already counted
        int already = 0;
        for(int k = 0; k < i; k++) {
            if(a[i] == a[k]) {
                already = 1;
                break;
            }
        }
        if(already) continue;

        // Count frequency
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                count++;
            }
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}
