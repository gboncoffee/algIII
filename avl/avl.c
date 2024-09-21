#include "avl.h"

#include <stdio.h>
#include <stdlib.h>

Node*
newNode(int key, Node* left, Node* right)
{
    Node* n = malloc(sizeof(Node));
    if (n == NULL)
        return NULL;

    n->key    = key;
    n->height = 1;
    n->left   = left;
    n->right  = right;
    return n;
}

void
freeNode(Node* node)
{
    free(node);
}

void
DeleteTree(Node* tree)
{
    if (tree->left != NULL)
        DeleteTree(tree->left);
    if (tree->right != NULL)
        DeleteTree(tree->right);
    freeNode(tree);
}

#define HEIGHT(t) ((t) == NULL ? 0 : (t)->height)

int
recomputeHeight(Node* x)
{
    int lh = HEIGHT(x->left);
    int rh = HEIGHT(x->right);
    return (lh > rh ? lh : rh) + 1;
}

Node*
rotateLeft(Node* x)
{
    Node* y;

    y        = x->right;
    x->right = y->left;
    y->left  = x;

    x->height = recomputeHeight(x);
    y->height = recomputeHeight(y);

    return y;
}

Node*
rotateRight(Node* x)
{
    Node* y;

    y        = x->left;
    x->left  = y->right;
    y->right = x;

    x->height = recomputeHeight(x);
    y->height = recomputeHeight(y);

    return y;
}

Node*
retrace(Node* tree)
{
    int childBf;
    int bf = HEIGHT(tree->left) - HEIGHT(tree->right);
    switch (bf)
    {
    case 1:
    case -1:
        tree->height++;
        break;
    case 2:
        childBf = HEIGHT((tree->left)->left) - HEIGHT((tree->left)->right);
        if (childBf == 1)
        {
            return rotateRight(tree);
        }
        else
        {
            tree->left = rotateLeft(tree->left);
            return rotateRight(tree);
        }
        break;
    case -2:
        childBf = HEIGHT((tree->right)->left) - HEIGHT((tree->right)->right);
        if (childBf == -1)
        {
            return rotateLeft(tree);
        }
        else
        {
            tree->right = rotateRight(tree->right);
            return rotateLeft(tree);
        }
        break;
    }

    return tree;
}

Node*
Insert(Node* tree, int key)
{
    if (tree == NULL)
        return newNode(key, NULL, NULL);

    if (tree->key > key)
        tree->left = Insert(tree->left, key);
    else
        tree->right = Insert(tree->right, key);

    return retrace(tree);
}

Node*
removeMax(Node* tree, int* key)
{
    Node* left;
    if (tree == NULL)
        return NULL;

    if (tree->right == NULL)
    {
        *key = tree->key;
        left = tree->left;
        freeNode(tree);
        return left;
    }

    tree->right = removeMax(tree->right, key);
    if (tree->left != NULL)
        tree->height = (tree->left)->height + 1;

    return tree;
}

Node*
Remove(Node* tree, int key)
{
    Node* ret;
    if (tree == NULL)
        return NULL;

    if (key < tree->key)
    {
        tree->left   = Remove(tree->left, key);
        tree->height = HEIGHT(tree->right) + 1;
        return tree;
    }
    if (key > tree->key)
    {
        tree->right  = Remove(tree->right, key);
        tree->height = HEIGHT(tree->left) + 1;
        return tree;
    }

    if (tree->right == NULL)
    {
        ret = tree->left;
        freeNode(tree);
        return ret;
    }
    if (tree->left == NULL)
    {
        ret = tree->right;
        freeNode(tree);
        return ret;
    }

    tree->left   = removeMax(tree->left, &tree->key);
    tree->height = (tree->right)->height + 1;

    return tree;
}

void
PrintInOrderWithHeights(Node* tree, int height)
{
    if (tree == NULL)
        return;

    PrintInOrderWithHeights(tree->left, height + 1);
    printf("%d,%d\n", tree->key, height);
    PrintInOrderWithHeights(tree->right, height + 1);
}
