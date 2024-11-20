#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem;
    struct _s_stack * next;
};

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e){
    stack s1 = malloc(sizeof(struct _s_stack));
    if (s1==NULL){
        printf("Error, the memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
    s1 -> elem = e;
    s1 -> next = s;
    s = s1;
    return s;
}

stack stack_pop(stack s){
    assert(s!=NULL);
    stack s1 = s;
    s = s->next;
    free(s1);
    return s;
}

unsigned int stack_size(stack s){
    unsigned int length = 0u;
    stack s1 = s;
    while (s1!=NULL){
        s1 = s1 -> next;
        length = length + 1;
    }
    return length;
}

stack_elem stack_top(stack s){
    assert(s!=NULL);
    return s -> elem;
}

bool stack_is_empty(stack s){
    return s==NULL;
}

stack_elem *stack_to_array(stack s){
    stack_elem *array = NULL;
    stack s1 = s;
    if (s1!=NULL){
        array = calloc(stack_size(s1), sizeof(stack_elem));
        if (array==NULL){
            printf("Error, the memory can't be allocated\n");
            exit(EXIT_FAILURE);
        }
        unsigned int i = 0u;
        while (i<stack_size(s1) && s1!=NULL){
            array[i] = s1 -> elem;
            s1 = s1 -> next;
            i = i + 1;
        }
    }
    return array;
}

stack stack_destroy(stack s){
    while (s!=NULL){
        stack destroy = s;
        s = s -> next;
        free(destroy);
        destroy = NULL;
    }
    return s;
}


