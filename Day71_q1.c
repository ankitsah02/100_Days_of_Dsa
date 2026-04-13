#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    
    scanf("%d", &m);   // Hash table size
    scanf("%d", &q);   // Number of operations

    int table[m];

    // Initialize table with EMPTY
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        // INSERT Operation
        if (strcmp(op, "INSERT") == 0) {
            int inserted = 0;

            for (int i = 0; i < m; i++) {
                int index = (key % m + i * i) % m;

                if (table[index] == EMPTY) {
                    table[index] = key;
                    inserted = 1;
                    break;
                }
            }

            if (!inserted) {
                printf("HASH TABLE FULL\n");
            }
        }

        // SEARCH Operation
        else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;

            for (int i = 0; i < m; i++) {
                int index = (key % m + i * i) % m;

                if (table[index] == EMPTY) {
                    break;
                }

                if (table[index] == key) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    return 0;
}