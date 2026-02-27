#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function to create a linked list
struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to merge two sorted lists
struct node* mergeLists(struct node *l1, struct node *l2)
{
    struct node *merged = NULL, *temp = NULL;

    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    // Initialize merged list
    if(l1->data < l2->data)
    {
        merged = l1;
        l1 = l1->next;
    }
    else
    {
        merged = l2;
        l2 = l2->next;
    }

    temp = merged;

    // Compare remaining nodes
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data < l2->data)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    // Attach remaining nodes
    if(l1 != NULL)
        temp->next = l1;
    else
        temp->next = l2;

    return merged;
}

// Function to print list
void printList(struct node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m;

    // First list
    scanf("%d", &n);
    struct node *list1 = createList(n);

    // Second list
    scanf("%d", &m);
    struct node *list2 = createList(m);

    // Merge
    struct node *result = mergeLists(list1, list2);

    // Print merged list
    printList(result);

    return 0;
}