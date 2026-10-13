#ifndef LL_H
#define LL_H

#include <stdint.h>
#include <stddef.h>

typedef struct ll_node {
    double value;
    struct ll_node *next;
} ll_node;

typedef struct ll_list {
    ll_node *head;
    uint32_t size;
} ll_list;

void ll_push_front(ll_list *list, double wert);
double ll_pop_front(ll_list *list);
void ll_add(ll_list *list, double wert);
double ll_removelast(ll_list *list);
int64_t ll_search(const ll_list *list, double wert);
int ll_remove_X(ll_list *list, uint32_t index, double *out);
double *ll_to_array(const ll_list *list, uint32_t *out_size);
void ll_clear(ll_list *list);

#endif