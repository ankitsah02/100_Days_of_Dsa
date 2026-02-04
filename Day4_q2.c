
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int nums[] = {3,2,2,3};
    int val = 3;
    int size = 4;

    int k = removeElement(nums, size, val);

    printf("k = %d\n", k);

    printf("Array: ");
    for(int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
