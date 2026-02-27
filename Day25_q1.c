#include <stdio.h>
#include <stdlib.h>

// structure definition
struct node
{
    int data;
    struct node *next;
};

struct node *first = NULL, *last = NULL, *newnode, *ptr;

// create linked list
void create(int n)
{
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

// count occurrences
int count_occurrence(int key)
{
    int count = 0;
    ptr = first;

    while(ptr != NULL)
    {
        if(ptr->data == key)
            count++;

        ptr = ptr->next;
    }

    return count;
}

int main()
{
    int n, key, result;

    scanf("%d", &n);
    create(n);

    scanf("%d", &key);

    result = count_occurrence(key);

    printf("%d", result);

    return 0;
}