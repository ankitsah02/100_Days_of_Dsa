#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL, *temp, *newnode;

// insert at end
void insert(int val) {
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

// rotate right by k
void rotate(int k) {
    if(head == NULL || k == 0) return;

    int count = 1;
    temp = head;

    // count nodes and reach last node
    while(temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // make circular
    temp->next = head;

    k = k % count;
    int steps = count - k;

    temp = head;
    for(int i = 1; i < steps; i++)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;
}

// display list
void display() {
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x, k;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }

    scanf("%d", &k);

    rotate(k);
    display();

    return 0;
}