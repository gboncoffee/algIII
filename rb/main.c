#include "rb.h"

#include <stdio.h>

int
main(void)
{
    RBTree tree;
    char   op;
    int    key;

    InitRBTree(&tree);

    while (scanf("%c %d\n", &op, &key) == 2)
    {
        switch (op)
        {
        case 'i':
            Insert(&tree, key);
            break;
        case 'r':
            Delete(&tree, key);
            break;
        }
    }

    PrintTree(&tree);
    DeleteTree(&tree);

    return 0;
}
