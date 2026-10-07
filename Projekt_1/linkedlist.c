#include "linkedlist.h"
#include <stdint.h>
#include <stdlib.h>

void ll_push_front(ll_list *list, double wert) {
    ll_node *neu = malloc(sizeof(ll_node));
    neu->value = wert;
    neu->next = list->head;
    list->head = neu;
    list->size++;
}

double ll_pop_front(ll_list *list) {
    double wert = list->head->value;
    ll_node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
    return wert;
}
void ll_add(ll_list *list, double wert) {
    ll_node *neu = malloc(sizeof(ll_node));
    neu->value = wert;
    neu->next = NULL;

    if (list-> head == NULL) {
        list -> head = neu;
    }
    else {
        ll_node* aktuell = list->head;
        while (aktuell->next != NULL) {
            aktuell = aktuell->next;
        }
        aktuell->next = neu;
    }
    list->size++;
}
double ll_removelast(ll_list* list) {
    if (list ->head -> next == NULL) {
        double wert = list -> head -> value;
        free(list-> head);
        list -> head = NULL;
        list -> size--;
        return wert;
    }
    else {
        ll_node* vorletzter = list->head;
        ll_node* letzter = list->head->next;

        while (letzter->next != NULL) {
            vorletzter = letzter;
            letzter = letzter -> next;
        }
        double wert = letzter -> value;
        free(letzter);
        vorletzter -> next = NULL;
        list -> size--;
        return wert;
    }
}
