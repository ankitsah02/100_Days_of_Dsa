#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // Using simple array as hashmap (for small constraints)
    // For large constraints use unordered_map in C++
    
    int hash[10000] = {0};
    int offset = 5000;  // To handle negative prefix sums
    
    hash[offset] = 1;   // prefix sum 0 initially occurs once

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        if(hash[prefixSum + offset] > 0) {
            count += hash[prefixSum + offset];
        }
        
        hash[prefixSum + offset]++;
    }

    printf("%d\n", count);
    
    return 0;
}