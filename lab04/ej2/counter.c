#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(unsigned int));
    if (c==NULL){
        printf("Error, the memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
    c -> count = 0;
    return c;
}

void counter_inc(counter c) {
    c -> count = c->count + 1;
}

bool counter_is_init(counter c) {
    bool b = c -> count == 0u;
    return b;
}

void counter_dec(counter c) {  
    assert(c->count!=0u);
    c -> count = c->count - 1u;
}

counter counter_copy(counter c) {
    counter c1 = malloc(sizeof(unsigned int));
    if (c==NULL){
        printf("Error, the memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
    c1 -> count = c -> count;
    return c1;
}

void counter_destroy(counter c) {
    if (c!=NULL){
        free(c);
    }
}
