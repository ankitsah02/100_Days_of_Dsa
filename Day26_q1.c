#include <stdio.h>
#include <stdlib.h>

// Define structure for doubly linked list node
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *temp = NULL, *newnode;

// Function to insert at end
void insert(int value)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

// Function to traverse forward
void traverse()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }

    traverse();

    return 0;
}