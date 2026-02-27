#include <stdio.h>
#include <stdlib.h>

// Define structure
struct node
{
    int data;
    struct node *next;
};

struct node *first = NULL, *temp, *newnode;

// Function to create linked list
void create(int n)
{
    struct node *last = NULL;
    int value;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(first == NULL)
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
    }
}

// Function to delete first occurrence of key
void delete_key(int key)
{
    struct node *ptr = first, *prev = NULL;

    // if first node itself is key
    if(ptr != NULL && ptr->data == key)
    {
        first = ptr->next;
        free(ptr);
        return;
    }

    // search for key
    while(ptr != NULL && ptr->data != key)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    // if key found
    if(ptr != NULL)
    {
        prev->next = ptr->next;
        free(ptr);
    }
}

// Function to display list
void display()
{
    temp = first;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, key;

    scanf("%d", &n);
    create(n);

    scanf("%d", &key);

    delete_key(key);

    display();

    return 0;
}