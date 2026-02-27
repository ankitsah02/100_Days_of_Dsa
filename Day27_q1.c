#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// function to create list
struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;
    int x;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// function to find intersection (by value)
int findIntersection(struct node *head1, struct node *head2)
{
    struct node *p1, *p2;

    for(p1 = head1; p1 != NULL; p1 = p1->next)
    {
        for(p2 = head2; p2 != NULL; p2 = p2->next)
        {
            if(p1->data == p2->data)
            {
                return p1->data;
            }
        }
    }
    return -1;
}

int main()
{
    int n, m, result;

    // first list
    scanf("%d", &n);
    struct node *head1 = createList(n);

    // second list
    scanf("%d", &m);
    struct node *head2 = createList(m);

    result = findIntersection(head1, head2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}