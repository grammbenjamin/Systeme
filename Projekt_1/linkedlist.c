#include "linkedlist.h"
#include <stdlib.h>

void ll_push_front(ll_list *list, double wert) {
    ll_node *neu = malloc(sizeof(ll_node));
    neu->value = wert;
    neu->next = list->head;
    list->head = neu;
    list->size++;
}

double ll_pop_front(ll_list *list) {
    if (list->head == NULL) return 0.0;
    ll_node *temp = list->head;
    double wert = temp->value;
    list->head = temp->next;
    free(temp);
    list->size--;
    return wert;
}

void ll_add(ll_list *list, double wert) {
    ll_node *neu = malloc(sizeof(ll_node));
    neu->value = wert;
    neu->next = NULL;
    if (list->head == NULL) {
        list->head = neu;
    } else {
        ll_node *aktuell = list->head;
        while (aktuell->next != NULL) {
            aktuell = aktuell->next;
        }
        aktuell->next = neu;
    }
    list->size++;
}

double ll_removelast(ll_list *list) {
    if (list->head == NULL) return 0.0;
    if (list->head->next == NULL) {
        return ll_pop_front(list);
    }
    ll_node *vorletzter = list->head;
    while (vorletzter->next->next != NULL) {
        vorletzter = vorletzter->next;
    }
    ll_node *letzter = vorletzter->next;
    double wert = letzter->value;
    vorletzter->next = NULL;
    free(letzter);
    list->size--;
    return wert;
}

int64_t ll_search(const ll_list *list, double wert) {
    const ll_node *aktuell = list->head;
    int64_t index = 0;
    while (aktuell != NULL) {
        if (aktuell->value == wert) return index;
        aktuell = aktuell->next;
        index++;
    }
    return -1;
}

int ll_remove_X(ll_list *list, uint64_t index, double *out) {
    if (index >= list->size) return -1;
    if (index == 0) {
        double wert = ll_pop_front(list);
        if (out) *out = wert;
        return 0;
    }
    ll_node *davor = list->head;
    for (uint32_t i = 0; i < index - 1; i++) {
        davor = davor->next;
    }
    ll_node *weg = davor->next;
    davor->next = weg->next;
    if (out) *out = weg->value;
    free(weg);
    list->size--;
    return 0;
}

double *ll_to_array(const ll_list *list, uint64_t *out_size) {
    *out_size = list->size;
    if (list->size == 0) return NULL;
    double *arr = malloc(list->size * sizeof(double));
    const ll_node *aktuell = list->head;
    for (uint32_t i = 0; aktuell != NULL; i++) {
        arr[i] = aktuell->value;
        aktuell = aktuell->next;
    }
    return arr;
}

void ll_clear(ll_list *list) {
    ll_node *aktuell = list->head;
    while (aktuell != NULL) {
        ll_node *naechster = aktuell->next;
        free(aktuell);
        aktuell = naechster;
    }
    list->head = NULL;
    list->size = 0;
}