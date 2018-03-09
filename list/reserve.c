#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

void print_list(Node *ptr)
{
    Node *temp = ptr;

    while (NULL != temp) {
        printf("data = %d\n", temp->data);
        temp = temp->next;
    }

    return;
}

Node * reverse(Node *ptr)
{
    Node *pre, *cur, *next;

    if (ptr == NULL) {
        return ptr;
    }

    if (ptr->next == NULL) {
        return ptr;
    }

    pre = ptr;
    cur = ptr->next;
    next = ptr->next->next;
    pre->next = NULL;

    while (NULL != cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

void main(int argc, char **argv)
{
    Node a[4] = {{1,NULL}, {2,NULL}, {3,NULL}, {4,NULL}};

    a[0].next = &a[1];
    a[1].next = &a[2];
    a[2].next = &a[3];
    a[3].next = NULL;

    print_list(&a[0]);

    print_list(reverse(&a[0]));
}
