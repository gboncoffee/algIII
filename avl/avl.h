#ifndef AVL_H_
#define AVL_H_

typedef struct Node
{
    struct Node* left;
    struct Node* right;
    int          key;
    int          height;
} Node;

Node* Insert(Node* tree, int key);
Node* Remove(Node* tree, int key);
void  PrintInOrderWithHeights(Node* tree, int height);
void  DeleteTree(Node* tree);

#endif /* AVL_H_ */
