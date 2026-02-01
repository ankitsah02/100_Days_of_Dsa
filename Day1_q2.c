#include <stdio.h>

int main() {
    int nums[] = {2,7,11,15};
    int n = 4;
    int target = 9;

    int map[1000]; 
    for(int i = 0; i < 1000; i++)
        map[i] = -1;

    for(int i = 0; i < n; i++) {
        int needed = target - nums[i];

        if(needed >= 0 && map[needed] != -1) {
            printf("[%d, %d]", map[needed], i);
            return 0;
        }

        map[nums[i]] = i;
    }

    return 0;
}
