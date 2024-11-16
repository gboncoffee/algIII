#ifndef RB_H_
#define RB_H_

typedef enum
{
    Black = 0,
    Red   = 1
} Color;

typedef struct Node
{
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int          key;
    Color        color;
} Node;

typedef struct
{
    Node  nil;
    Node* root;
} RBTree;

void InitRBTree(RBTree* tree);
void Insert(RBTree* tree, int key);
void Delete(RBTree* tree, int key);
void PrintTree(RBTree* tree);
void DeleteTree(RBTree* tree);

#endif /* RB_H_ */
