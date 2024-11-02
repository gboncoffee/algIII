#ifndef HT_H_
#define HT_H_

#define M (11)

typedef enum
{
    Empty = 0,
    Occupied,
    Excluded
} EntryState;

typedef struct
{
    int  value;
    char state;
} HashEntry;

typedef struct
{
    HashEntry t1[M];
    HashEntry t2[M];
} HashMap;

void InitMap(HashMap* map);
void Insert(HashMap* map, int key);
void Remove(HashMap* map, int key);
int* Search(HashMap* map, int key);
void PrintTables(HashMap* map);

#endif /* HT_H_ */
