#include "ht.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
InitMap(HashMap* map)
{
    memset(map, 0, sizeof(*map));
}

int
Hash1(int k)
{
    return k % M;
}

int
Hash2(int k)
{
    float fk = ((float) k) * 0.9;
    return (int) floor(M * (fk - floor(fk)));
}

int*
Search(HashMap* map, int key)
{
    HashEntry* entry = &(map->t1[Hash1(key)]);
    if (entry->state == Empty)
        return NULL;
    if (entry->state == Occupied && entry->value == key)
        return &entry->value;
    return &(map->t2[Hash2(key)].value);
}

void
Insert(HashMap* map, int key)
{
    int pt2;
    int pt1 = Hash1(key);
    if (map->t1[pt1].state != Occupied)
    {
        map->t1[pt1].value = key;
        map->t1[pt1].state = Occupied;
        return;
    }

    if (map->t1[pt1].value == key)
        return;

    pt2                = Hash2(map->t1[pt1].value);
    map->t2[pt2].value = map->t1[pt1].value;
    map->t2[pt2].state = Occupied;
    map->t1[pt1].value = key;
}

void
Remove(HashMap* map, int key)
{
    int pt1;
    int pt2 = Hash2(key);
    if (map->t2[pt2].state == Occupied && map->t2[pt2].value == key)
    {
        map->t2[pt2].state = Empty;
        return;
    }

    pt1 = Hash1(key);
    if (map->t1[pt1].state == Occupied && map->t1[pt1].value == key)
        map->t1[pt1].state = Excluded;
}

typedef struct
{
    int  key;
    char table; /* 1 or 2. */
    char pos;
} PrintEntry;

int
CompareEntries(const void* aVoid, const void* bVoid)
{
    const PrintEntry* a = aVoid;
    const PrintEntry* b = bVoid;

    if (a->key < b->key)
        return -1;
    if (a->key > b->key)
        return 1;

    if (a->table < b->table)
        return -1;
    if (a->table > b->table)
        return 1;

    if (a->pos < b->pos)
        return -1;
    if (a->pos > b->pos)
        return 1;

    return 0;
}

void
PrintTables(HashMap* map)
{
    int        i;
    PrintEntry entries[M * 2];
    int        numberOfEntries = 0;
    for (i = 0; i < M; i += 1)
    {
        if (map->t1[i].state == Occupied)
        {
            entries[numberOfEntries].key   = map->t1[i].value;
            entries[numberOfEntries].pos   = i;
            entries[numberOfEntries].table = 1;
            numberOfEntries += 1;
        }
    }
    for (i = 0; i < M; i += 1)
    {
        if (map->t2[i].state == Occupied)
        {
            entries[numberOfEntries].key   = map->t2[i].value;
            entries[numberOfEntries].pos   = i;
            entries[numberOfEntries].table = 2;
            numberOfEntries += 1;
        }
    }

    if (numberOfEntries <= 1)
        return;

    qsort(entries, numberOfEntries, sizeof(*entries), CompareEntries);

    for (i = 0; i < numberOfEntries; i += 1)
        printf("%d,T%d,%d\n", entries[i].key, entries[i].table, entries[i].pos);
}
