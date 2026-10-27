#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "linkedlist.h"
#include "doublelinkedlist.h"

static void ausgeben_ll(ll_list *l) {
    uint64_t n;
    double *arr = ll_to_array(l, &n);
    for (uint64_t i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    free(arr);
}

static void ausgeben_dll(dll_list *l) {
    uint32_t n;
    double *arr = dll_to_array(l, &n);
    for (uint32_t i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    free(arr);
}

static void test_ll(void) {
    ll_list l = {.head = NULL, .size = 0};

    printf("===== Einfach verkettete Liste (ll) =====\n");

    // Teil 1: Funktionstest
    ll_push_front(&l, 10.5);
    printf("push_front 10.50: ");
    ausgeben_ll(&l);

    ll_add(&l, 20.0);
    ll_add(&l, 30.25);
    printf("add 20, 30.25: ");
    ausgeben_ll(&l);

    printf("search 20.00: Index %lld\n", (long long)ll_search(&l, 20.0));

    ll_remove_X(&l, 1, NULL);
    printf("remove_X 1: ");
    ausgeben_ll(&l);

    printf("pop_front: %.2f\n", ll_pop_front(&l));
    printf("removelast: %.2f\n", ll_removelast(&l));
    printf("Liste jetzt: ");
    ausgeben_ll(&l);

    ll_clear(&l);

    // Teil 2: Zeitmessung
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

    printf("Einfügen am Anfang:   %.3f s\n", t_front);
    printf("Einfügen am Ende:     %.3f s\n", t_back);
    printf("Suchen in der Mitte:  %.3f s\n", t_search);
    printf("Entfernen von hinten: %.3f s\n", t_pop);

    ll_clear(&l);
}

static void test_dll(void) {
    dll_list l = {.head = NULL, .tail = NULL, .size = 0};

    printf("\n===== Doppelt verkettete Liste (dll) =====\n");

    // Teil 1: Funktionstest
    dll_push_front(&l, 10.5);
    printf("push_front 10.50: ");
    ausgeben_dll(&l);

    dll_add(&l, 20.0);
    dll_add(&l, 30.25);
    printf("add 20, 30.25: ");
    ausgeben_dll(&l);

    printf("search 20.00: Index %lld\n", (long long)dll_search(&l, 20.0));

    dll_remove_X(&l, 1, NULL);
    printf("remove_X 1: ");
    ausgeben_dll(&l);

    printf("pop_front: %.2f\n", dll_pop_front(&l));
    printf("removelast: %.2f\n", dll_removelast(&l));
    printf("Liste jetzt: ");
    ausgeben_dll(&l);

    dll_clear(&l);

    // Teil 2: Zeitmessung
    uint32_t N = 30000;
    clock_t start, ende;

    start = clock();
    for (uint32_t i = 0; i < N; i++) dll_push_front(&l, i);
    ende = clock();
    double t_front = (double)(ende - start) / CLOCKS_PER_SEC;
    dll_clear(&l);

    start = clock();
    for (uint32_t i = 0; i < N; i++) dll_add(&l, i);
    ende = clock();
    double t_back = (double)(ende - start) / CLOCKS_PER_SEC;

    start = clock();
    for (uint32_t i = 0; i < N; i++) dll_search(&l, N / 2);
    ende = clock();
    double t_search = (double)(ende - start) / CLOCKS_PER_SEC;

    start = clock();
    for (uint32_t i = 0; i < N; i++) dll_removelast(&l);
    ende = clock();
    double t_pop = (double)(ende - start) / CLOCKS_PER_SEC;

    printf("Einfügen am Anfang:   %.3f s\n", t_front);
    printf("Einfügen am Ende:     %.3f s\n", t_back);
    printf("Suchen in der Mitte:  %.3f s\n", t_search);
    printf("Entfernen von hinten: %.3f s\n", t_pop);

    dll_clear(&l);
}

int main(void) {
    test_ll();
    test_dll();
    return 0;
}