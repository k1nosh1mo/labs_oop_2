#ifndef LIST_H
#define LIST_H

typedef struct Item {
    struct Item *next;
    struct Item *prev;
} Item;
typedef struct List {
    Item *head;
    Item *tail;
} List;

void Add(List *list, Item *item);
void Delete(List *list, int index);
Item* GetItem(const List *list, int index);
Item* Remove(List *list, int index);
void Insert(List *list, Item *item, int index);
int Count(const List *list);
void Clear(List *list);
int GetIndex(const List *list, Item *item);

#endif