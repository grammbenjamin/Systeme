#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "linkedlist.h"

void ausgeben(ll_list *l) {
    uint32_t n;
    double *arr = ll_to_array(l, &n);
    for (uint32_t i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    free(arr);
}

int main(void) {
    ll_list l = {.head = NULL, .size = 0};

// teil 1

    ll_push_front(&l, 10.5);
    printf("push_front 10.50: ");
    ausgeben(&l);

    ll_add(&l, 20.0);
    ll_add(&l, 30.25);
    printf("add 20, 30.25: ");
    ausgeben(&l);

    printf("search 20.00: Index %lld\n", (long long)ll_search(&l, 20.0));

    ll_remove_X(&l, 1, NULL);
    printf("remove_X 1: ");
    ausgeben(&l);

    printf("pop_front: %.2f\n", ll_pop_front(&l));
    printf("removelast: %.2f\n", ll_removelast(&l));
    printf("Liste jetzt: ");
    ausgeben(&l);

    ll_clear(&l);

// teil 2
    uint32_t N = 30000;
    clock_t start, ende;

    start = clock();
    for (uint32_t i = 0; i < N; i++) ll_push_front(&l, i);
    ende = clock();
    double t_front = (double)(ende - start) / CLOCKS_PER_SEC;
    ll_clear(&l);

    start = clock();
    for (uint32_t i = 0; i < N; i++) ll_add(&l, i);
    ende = clock();
    double t_back = (double)(ende - start) / CLOCKS_PER_SEC;

    start = clock();
    for (uint32_t i = 0; i < N; i++) ll_search(&l, N / 2);
    ende = clock();
    double t_search = (double)(ende - start) / CLOCKS_PER_SEC;

    start = clock();
    for (uint32_t i = 0; i < N; i++) ll_removelast(&l);
    ende = clock();
    double t_pop = (double)(ende - start) / CLOCKS_PER_SEC;


    printf("Einfügen am anfang:  %.3f s\n", t_front);
    printf("Einfügen am Ende:    %.3f s\n", t_back);
    printf("Suchen in der Mite:  %.3f s\n", t_search);
    printf("Entfernen von Hinten: %.3f s\n", t_pop);

    ll_clear(&l);
    return 0;
}