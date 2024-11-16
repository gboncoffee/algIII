#include "rb.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Code is literally the Cormen.
 */

void
InitRBTree(RBTree* tree)
{
    tree->nil.color  = Black;
    tree->nil.left   = &tree->nil;
    tree->nil.right  = &tree->nil;
    tree->nil.parent = &tree->nil;

    tree->root = &tree->nil;
}

void
RotateLeft(RBTree* tree, Node* x)
{
    Node* y;
    assert(x != NULL);

    y        = x->right;
    x->right = y->left;

    if (y->left != &tree->nil)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == &tree->nil)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left   = x;
    x->parent = y;
}

void
RotateRight(RBTree* tree, Node* x)
{
    Node* y;
    assert(x != NULL);

    y       = x->left;
    x->left = y->right;

    if (y->right != &tree->nil)
        y->right->parent = x;

    y->parent = x->parent;
    if (x->parent == &tree->nil)
        tree->root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right  = x;
    x->parent = y;
}

void
Insert(RBTree* tree, int key)
{
    Node* z;
    Node* x = tree->root;
    Node* y = &tree->nil;

    while (x != &tree->nil)
    {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z         = malloc(sizeof(*z));
    z->parent = y;
    z->key    = key;
    z->left   = &tree->nil;
    z->right  = &tree->nil;
    z->color  = Red;

    if (y == &tree->nil)
        tree->root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    z->left  = &tree->nil;
    z->right = &tree->nil;
    z->color = Red;

    /* Insert fixup algorithm. */

    while (z->parent->color == Red)
    {
        if (z->parent != &tree->nil && z->parent->parent != &tree->nil)
        {
            if (z->parent == z->parent->parent->left)
            {
                y = z->parent->parent->right;
                if (y->color == Red)
                {
                    z->parent->color         = Black;
                    y->color                 = Black;
                    z->parent->parent->color = Red;
                    z                        = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        RotateLeft(tree, z);
                    }

                    z->parent->color         = Black;
                    z->parent->parent->color = Red;
                    RotateRight(tree, z->parent->parent);
                }
            }
            else
            {
                y = z->parent->parent->left;
                if (y->color == Red)
                {
                    z->parent->color         = Black;
                    y->color                 = Black;
                    z->parent->parent->color = Red;
                    z                        = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        RotateRight(tree, z);
                    }

                    z->parent->color         = Black;
                    z->parent->parent->color = Red;
                    RotateLeft(tree, z->parent->parent);
                }
            }
        }
    }

    tree->root->color = Black;
}

void
Transplant(RBTree* tree, Node* u, Node* v)
{
    if (u->parent == &tree->nil)
        tree->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

Node*
Find(RBTree* tree, int key)
{
    Node* x = tree->root;
    while (x != &tree->nil && x->key != key)
    {
        if (x->key > key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

Node*
FindMaximum(RBTree* tree, Node* node)
{
    if (node->right != &tree->nil)
        return FindMaximum(tree, node->right);
    return node;
}

void
Delete(RBTree* tree, int key)
{
    Node* x;
    Node* w;
    Node* z              = Find(tree, key);
    Node* y              = z;
    Color yOriginalColor = y->color;

    if (z->left == &tree->nil)
    {
        x = z->right;
        Transplant(tree, z, z->right);
        free(z);
    }
    else if (z->right == &tree->nil)
    {
        x = z->left;
        Transplant(tree, z, z->left);
        free(z);
    }
    else
    {
        y              = FindMaximum(tree, z->left);
        yOriginalColor = y->color;

        x = y->right;
        if (y != z->right)
        {
            Transplant(tree, y, y->right);
            y->right         = z->right;
            y->right->parent = y;
        }
        else
        {
            x->parent = y;
        }
        Transplant(tree, z, y);
        y->left         = z->left;
        y->left->parent = y;
        y->color        = z->color;
        free(z);
    }

    if (yOriginalColor == Black)
    {
        /* Delete fixup algorithm. */

        while (x != tree->root && x->color == Black)
        {
            if (x == x->parent->left)
            {
                w = x->parent->right;
                if (w->color == Red)
                {
                    w->color         = Black;
                    x->parent->color = Red;
                    RotateLeft(tree, x->parent);
                    w = x->parent->right;
                }

                if (w->left->color == Black && w->right->color == Black)
                {
                    w->color = Red;
                    x        = x->parent;
                }
                else
                {
                    if (w->right->color == Black)
                    {
                        w->left->color = Black;
                        w->color       = Red;
                        RotateRight(tree, w);
                        w = x->parent->right;
                    }

                    w->color         = x->parent->color;
                    x->parent->color = Black;
                    w->right->color  = Black;
                    RotateLeft(tree, x->parent);
                    x = tree->root;
                }
            }
            else
            {
                w = x->parent->left;
                if (w->color == Red)
                {
                    w->color         = Black;
                    x->parent->color = Red;
                    RotateRight(tree, x->parent);
                    w = x->parent->left;
                }

                if (w->right->color == Black && w->left->color == Black)
                {
                    w->color = Red;
                    x        = x->parent;
                }
                else
                {
                    if (w->left->color == Black)
                    {
                        w->right->color = Black;
                        w->color        = Red;
                        RotateLeft(tree, w);
                        w = x->parent->left;
                    }

                    w->color         = x->parent->color;
                    x->parent->color = Black;
                    w->left->color   = Black;
                    RotateRight(tree, x->parent);
                    x = tree->root;
                }
            }
        }

        x->color = Black;
    }
}

void
PrintTreeInner(RBTree* tree, Node* node, int height)
{
    if (node == &tree->nil)
        return;

    PrintTreeInner(tree, node->left, height + 1);
    printf("%d,%d,%d\n", node->key, height, node->color);
    PrintTreeInner(tree, node->right, height + 1);
}

void
PrintTree(RBTree* tree)
{
    PrintTreeInner(tree, tree->root, 0);
}

void
DeleteTreeInner(RBTree* tree, Node* node)
{
    Node* left  = node->left;
    Node* right = node->right;

    if (node == &tree->nil)
        return;

    free(node);
    DeleteTreeInner(tree, left);
    DeleteTreeInner(tree, right);
}

void
DeleteTree(RBTree* tree)
{
    DeleteTreeInner(tree, tree->root);
}
