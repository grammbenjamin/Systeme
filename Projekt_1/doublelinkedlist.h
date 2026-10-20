
#ifndef PROJEKT_1_DOUBLELINKEDLIST_H
#define PROJEKT_1_DOUBLELINKEDLIST_H
#include <stdint.h>


typedef struct dll_node {
    double value;
    struct dll_node* next;
    struct dll_node* prev;
}dll_node;

typedef struct dll_list {
    dll_node *head;
    dll_node *tail;
    uint32_t size;
}dll_list;

void ll_push_front(dll_list *list, double wert);
double ll_pop_front(dll_list *list);
void ll_add(dll_list *list, double wert);
double ll_removelast(dll_list *list);
int64_t ll_search(const dll_list *list, double wert);
int ll_remove_X(dll_list *list, uint32_t index, double *out);
double *ll_to_array(const dll_list *list, uint32_t *out_size);
void ll_clear(dll_list *list);

#endif //PROJEKT_1_DOUBLELINKEDLIST_H
