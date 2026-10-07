#include <stdio.h>
#include "linkedlist.h"

int main(void) {

    ll_list stack = {.head = NULL, .size =0};

    ll_add(&stack, 99);
    ll_add(&stack, 97);


    printf("Pop: %.2f\n", ll_pop_front(&stack));
    printf("Removed: %.2f\n", ll_removelast(&stack));
    return 0;
}


