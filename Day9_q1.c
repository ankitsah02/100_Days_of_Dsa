#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    
    // Input
    scanf("%s", s);

    int len = strlen(s);

    // Reverse and print
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }

    return 0;
}
