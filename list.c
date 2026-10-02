#include <stdlib.h>
#include "list.h"

void Add(List *list,Item *item) {
    if (list == NULL || item == NULL) return;
    item->next = NULL;
    item->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = item;
    }
    else {
        list->head = item;
    }
    list->tail = item;
}
int Count(const List *list) {
    int n = 0;
    Item *p;
    if (list == NULL) return 0;
    p = list->head;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    return n;
}
Item* GetItem(const List *list,int index) {
    Item *p;
    int i = 0;
    if (list == NULL || index < 0) return NULL;
    p = list->head;
    while (p != NULL && i < index) {
        p = p->next;
        i++;
    }
    return p;
}
Item* Remove(List *list, int index) {
    Item *p = GetItem(list,index);
    if (p == NULL) return NULL;
    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        list->head = p->next;
    }
    if (p->next != NULL) {
        p->next->prev = p->prev;
    } else {
        list->tail = p->prev;
    }
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void Delete(List *list, int index) {
    Item *p = Remove(list,index);
    if (p != NULL) {
        free(p);
    }
}
void Insert(List *list, Item *item, int index) {
    Item *pn = GetItem(list,index);
    if (pn == NULL) {
        Add(list,item);
        return;
    }
    if (pn == list->head) {
        item->prev = NULL;
        item->next = list->head;
        list->head->prev = item;
        list->head = item;
        return;
    }
    Item *pp = pn->prev;
    item->prev = pp;
    item->next = pn;
    pn->prev = item;
    pp->next = item;
}
void Clear(List *list) {
    if (list == NULL) return;
    while (list->head) {
        Delete(list, 0);
    }
    list->head = NULL;
    list->tail = NULL;
}
int GetIndex(const List *list, Item *item) {
    if (list == NULL || item == NULL) {
        return -1;
    }
    Item *p = list->head;
    int i = 0;
    while (p!=NULL) {
        if (p == item) {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}