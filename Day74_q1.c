#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char votes[n][100];
    char names[n][100];
    int count[n];

    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);

        int found = 0;

        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(names[j], votes[i]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(names[uniqueCount], votes[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    char winner[100];
    int maxVotes = 0;

    strcpy(winner, names[0]);
    maxVotes = count[0];

    for (int i = 1; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}