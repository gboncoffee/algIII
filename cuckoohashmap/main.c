#include "ht.h"

#include <stdio.h>

int
main(void)
{
    char    op;
    int     key;
    HashMap map;
    InitMap(&map);

    while (!feof(stdin) && scanf("%c %d\n", &op, &key) == 2)
    {
        switch (op)
        {
        case 'i':
            Insert(&map, key);
            break;
        case 'r':
            Remove(&map, key);
            break;
        }
    }

    PrintTables(&map);

    return 0;
}
