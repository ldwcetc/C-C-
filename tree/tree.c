#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    struct _node *p_left;
    int value;
    struct _node *p_right;
}node, *p_node;

p_node create_node(int data)
{
    p_node root;

    root = (p_node)malloc(sizeof(node));
    root->value = data;
    root->p_left = NULL;
    root->p_right = NULL;

    return root;
}

void printDLR(p_node root)
{
    if (NULL != root) {
        printf("%d ", root->value);
        printDLR(root->p_left);
        printDLR(root->p_right);
    }
}

void printLDR(p_node root)
{
    if (NULL != root) {
        printLDR(root->p_left);
        printf("%d ", root->value);
        printLDR(root->p_right);
    }
}

void printLRD(p_node root)
{
    if (NULL != root) {
        printLRD(root->p_left);
        printLRD(root->p_right);
        printf("%d ", root->value);
    }
}

void printLEVEL(p_node root)
{
    int front = 0;
    int rear = 0;
    p_node queue[50];
    p_node temp = NULL;

    if (NULL != root) {
        queue[rear++] = root;
        while (front != rear) {
            temp = queue[front++];

            if (NULL != temp->p_left) {
                queue[rear++] = temp->p_left;
            }

            if (NULL != temp->p_right) {
                queue[rear++] = temp->p_right;
            }

            printf("%d ", temp->value);
        }
    }
}

unsigned int get_level_of_tree(p_node root)
{
    unsigned int level = 0;

    if (NULL != root) {
        level = 1;
        level += get_level_of_tree(root->p_left) > get_level_of_tree(root->p_right) ? get_level_of_tree(root->p_left):get_level_of_tree(root->p_right);
    }

    return level;
}

unsigned int get_count_of_tree(p_node root)
{
    unsigned count = 0;

    if (NULL != root) {
        count++;
        count += get_count_of_tree(root->p_left);
        count += get_count_of_tree(root->p_right);
    }

    return count;
}

p_node create_btree(p_node root, int n)
{
    p_node left = NULL;
    p_node right = NULL;

    if (n>1) {
        left = (p_node)malloc(sizeof(node));
        right = (p_node)malloc(sizeof(node));
        printf("Please input left value: ");
        scanf("%d", &(left->value));
        printf("Please input right value: ");
        scanf("%d", &(right->value));
        root->p_left = left;
        root->p_right = right;
        left->p_left = NULL;
        left->p_right = NULL;
        right->p_left = NULL;
        right->p_right = NULL;

        create_btree(left, n-1);
        create_btree(right, n-1);
    }
}

void destroy_btree(p_node root)
{
    if (NULL != root) {
        destroy_btree(root->p_left);
        destroy_btree(root->p_right);
        free(root);
    }
}

int main(int argc, char **argv)
{
    unsigned int level = 0;
    unsigned int count = 0;

    p_node root = create_node(0);
    create_btree(root, 3);

    printf("先序遍历：");
    printDLR(root);

    printf("\n中序遍历：");
    printLDR(root);

    printf("\n后序遍历：");
    printLRD(root);

    printf("\n分层遍历：");
    printLEVEL(root);
    printf("\n");

    level = get_level_of_tree(root);
    printf("level of btree is: %u\n", level);

    count = get_count_of_tree(root);
    printf("count of btree is: %u\n", count);

    destroy_btree(root);
    return 0;
}
