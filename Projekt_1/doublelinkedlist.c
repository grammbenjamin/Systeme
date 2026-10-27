#include "doublelinkedlist.h"
#include <stdlib.h>

void dll_push_front(dll_list *list, double wert) {
    dll_node *neu = malloc(sizeof(dll_node));
    neu->value = wert;
    neu->prev = NULL;
    neu->next = list->head;
    if (list->head != NULL) {
        list->head->prev = neu;
    } else {
        list->tail = neu;
    }
    list->head = neu;
    list->size++;
}

double dll_pop_front(dll_list *list) {
    if (list->head == NULL) return 0.0;
    dll_node *temp = list->head;
    double wert = temp->value;
    list->head = temp->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    free(temp);
    list->size--;
    return wert;
}

void dll_add(dll_list *list, double wert) {
    dll_node *neu = malloc(sizeof(dll_node));
    neu->value = wert;
    neu->next = NULL;
    neu->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = neu;
    } else {
        list->head = neu;
    }
    list->tail = neu;
    list->size++;
}

double dll_removelast(dll_list *list) {
    if (list->tail == NULL) return 0.0;
    dll_node *letzter = list->tail;
    double wert = letzter->value;
    list->tail = letzter->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(letzter);
    list->size--;
    return wert;
}

int64_t dll_search(const dll_list *list, double wert) {
    const dll_node *aktuell = list->head;
    int64_t index = 0;
    while (aktuell != NULL) {
        if (aktuell->value == wert) return index;
        aktuell = aktuell->next;
        index++;
    }
    return -1;
}

int dll_remove_X(dll_list *list, uint32_t index, double *out) {
    if (index >= list->size) return -1;

    if (index == 0) {
        double wert = dll_pop_front(list);
        if (out) *out = wert;
        return 0;
    }
    if (index == list->size - 1) {
        double wert = dll_removelast(list);
        if (out) *out = wert;
        return 0;
    }

    dll_node *weg;
    if (index < list->size / 2) {
        weg = list->head;
        for (uint32_t i = 0; i < index; i++) weg = weg->next;
    } else {
        weg = list->tail;
        for (uint32_t i = list->size - 1; i > index; i--) weg = weg->prev;
    }

    weg->prev->next = weg->next;
    weg->next->prev = weg->prev;
    if (out) *out = weg->value;
    free(weg);
    list->size--;
    return 0;
}

double *dll_to_array(const dll_list *list, uint32_t *out_size) {
    *out_size = list->size;
    if (list->size == 0) return NULL;
    double *arr = malloc(list->size * sizeof(double));
    const dll_node *aktuell = list->head;
    for (uint32_t i = 0; aktuell != NULL; i++) {
        arr[i] = aktuell->value;
        aktuell = aktuell->next;
    }
    return arr;
}

void dll_clear(dll_list *list) {
    dll_node *aktuell = list->head;
    while (aktuell != NULL) {
        dll_node *naechster = aktuell->next;
        free(aktuell);
        aktuell = naechster;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}