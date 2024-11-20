#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
 
struct _s_stack {
    unsigned int size;
    struct _stack * fst;
};

struct _stack {
    stack_elem elem;
    struct _stack * next;
};

bool invrep(stack s){
    return (s!=NULL); 
}

stack stack_empty(){    
    stack s = malloc(sizeof(struct _s_stack));
    if (s==NULL){
        printf("Error, the memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
    s -> fst = NULL;
    s -> size = 0u;
    invrep(s);
    return s;
}

stack stack_push(stack s, stack_elem e){
    assert(invrep(s));
    struct _stack * p = malloc(sizeof(struct _stack));
    if (p==NULL){
        printf("Error, the memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
    p -> elem = e;
    p -> next = s -> fst;
    s -> fst = p;
    s -> size = s -> size + 1;
    assert(invrep(s));
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s) && !stack_is_empty(s));
    struct _stack *destroy = s->fst;
    s->fst = destroy->next;
    s->size = s->size - 1;
    free(destroy);
    destroy = NULL;
    assert(invrep(s));
    return s;
}

unsigned int stack_size(stack s){
    assert(invrep(s));
    return s->size;
}

stack_elem stack_top(stack s){
    assert(invrep(s) && !stack_is_empty(s));
    return (s->fst)->elem;
}

bool stack_is_empty(stack s){
    assert(invrep(s));
    return s->size==0u;
}

stack_elem *stack_to_array(stack s){
    assert(invrep(s));
    stack_elem *array = NULL;
    struct _stack *node = s->fst;
    if (node!=NULL){
        array = calloc(stack_size(s), sizeof(stack_elem));
        if (array==NULL){
            printf("Error, the memory can't be allocated\n");
            exit(EXIT_FAILURE);
        }
        unsigned int i = stack_size(s) - 1;
        while (node!=NULL){
            array[i] = node->elem;
            node = node->next;
            i = i - 1u;
        }
    }
    return array;
}

stack stack_destroy(stack s){
    assert(invrep(s));
    while (s->fst!=NULL){
        struct _stack * destroy = s->fst;
        s->fst = (s->fst)->next;
        free(destroy);
        destroy=NULL;
    }
    free(s);
    s=NULL;
    assert(s==NULL);
    return s;
}


