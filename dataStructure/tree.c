#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

void freeTree(node *root);
void printTree(node *root);

int main(void)
{
    // Tree of size 0
    node *tree = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if(n==NULL)
    {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    // Add number to list
    n = malloc(sizeof(node));
    if(n==NULL)
    {
        return 1;
    }
    n->number = 1;
    n ->left = NULL;
    n ->right = NULL;
    tree->left = n;

    // Add number to list
    n=malloc(sizeof(node));
    if(n==NULL)
    {
        return 1;
    }

    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    printTree(tree);
    freeTree(tree);

    return 0;
}

bool search(node *tree, int num)
{
    if(tree == NULL)
    {
        return false;
    }
    else if(num < tree->number)
    {
        return search(tree ->left, num);
    }
    else if(num > tree->number)
    {
        return search(tree->right, num);
    }
    else
    {
        return true;
    }

}

void freeTree(node *root)
{
    if(root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    freeTree(root);
}

void printTree(node *root)
{
    if(root==NULL)
    {
        return;
    }
    printTree(root->left);
    printf("%i\n", root->number);
    printTree(root->right);
}