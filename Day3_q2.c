#include <stdio.h>

int main() {
    int m;   // m = size of array (n-1)
    scanf("%d", &m);

    int arr[m];
    long long sum = 0;

    // Input array elements
    for(int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int n = m + 1;   // total numbers from 1 to n
    long long total = (long long)n * (n + 1) / 2;

    long long missing = total - sum;

    printf("%lld\n", missing);

    return 0;
}
