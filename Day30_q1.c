#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

struct Node* head = NULL, *temp, *newnode;

// insert at end
void insert(int c, int e) {
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coef = c;
    newnode->exp = e;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

// display polynomial
void display() {
    temp = head;
    while(temp != NULL) {
        if(temp->exp == 0)
            printf("%d", temp->coef);
        else if(temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%dx^%d", temp->coef, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n, c, e;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        insert(c, e);
    }

    display();
    return 0;
}