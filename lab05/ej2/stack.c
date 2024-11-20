#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#define MAX_CAPACITY 100

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool invrep(stack s){
    return (s->size<=s->capacity && s!=NULL);
}

stack stack_empty(){
    stack s = malloc(sizeof(struct _s_stack));
    s -> elems = NULL;
    s -> size = 0u;
    s -> capacity = 0u;
    assert(invrep(s));
    return s;
}

stack stack_push(stack s, stack_elem e){
    assert(invrep(s));
    if (s->elems==NULL){
        s -> capacity = MAX_CAPACITY;   
        s -> elems = calloc(s->capacity, sizeof(stack_elem));
        s->elems[0] = e;
    } else {
        if (s->size<s->capacity){
            (s->elems)[s->size] = e;
        } else if (s->size==s->capacity){
            s -> elems = realloc(s->elems, s->capacity*2);
            (s->elems)[s->size] = e;
            s -> capacity = s->capacity*2;
        }
    }
    s -> size = s -> size + 1;
    assert(invrep(s));
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s) && !stack_is_empty(s));
    s -> size = s -> size - 1u;
    assert(invrep(s));
    return s;
}

unsigned int stack_size(stack s){
    assert(invrep(s));
    return s->size;
}

stack_elem stack_top(stack s){
    assert(invrep(s) && !stack_is_empty(s));
    return (s->elems)[s->size-1u];
}

bool stack_is_empty(stack s){
    assert(invrep(s));
    return (s->elems==NULL && s->size==0u && s->capacity==0u);
}

stack_elem *stack_to_array(stack s){
    assert(invrep(s));
    stack_elem *array = NULL;
    if (s->elems!=NULL){
        array = calloc(s->size,sizeof(stack_elem));
        for (unsigned int i = 0u; i < s->size; i++)
        {
            array[i] = s->elems[i];
        }
    }
    return array;
}

stack stack_destroy(stack s){
    assert(invrep(s));
    if (s->elems!=NULL) {
        free(s->elems);
        s->elems=NULL;
    }
    free(s);
    s=NULL;
    assert(s==NULL);
    return s;
}