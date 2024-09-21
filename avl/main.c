#include "avl.h"

#include <stdio.h>

int
main(void)
{
    int   number;
    char  op;
    Node* tree = NULL;

    while (!feof(stdin))
    {
        scanf("%c %d\n", &op, &number);

        switch (op)
        {
        case 'i':
            tree = Insert(tree, number);
            break;
        case 'r':
            tree = Remove(tree, number);
            break;
        }
    }

    PrintInOrderWithHeights(tree, 0);
    DeleteTree(tree);

    return 0;
}
