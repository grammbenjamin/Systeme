#ifndef LL_H
#define LL_H
#include <stdlib.h>
#include <stdio.h>

typedef struct ll_node {
    double value;
    struct ll_node* next;
} ll_node;
typedef struct ll_list {
    ll_node* head;
    size_t size;
} ll_list;

void ll_push_front(ll_list* list, double wert);
double ll_pop_front(ll_list* list);
void ll_add(ll_list* list, double wert);
double ll_removelast(ll_list* list);

#endif