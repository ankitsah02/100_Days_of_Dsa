#include <stdio.h>

void moveZeroes(int nums[], int n) {
    int j = 0;  // position for next non-zero

    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            // swap nums[i] and nums[j]
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}

int main() {
    int nums[] = {0,1,0,3,12};
    int n = 5;

    moveZeroes(nums, n);

    // print result
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
