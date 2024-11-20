#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem elem;
    struct _s_stack * next;
};


int main(void){
    stack s = stack_empty();
    s = stack_push(s, 3);
    s = stack_pop(s);
    bool b = s==NULL;
    printf("%d\n", b);
    stack_elem *array = stack_to_array(NULL);
    b = array==NULL;
    printf("%d\n", b);
    s = stack_push(s, (-1));
    s = stack_push(s, 2);
    s = stack_push(s, 3);
    array = stack_to_array(s);
    free(array);
    stack_destroy(s);
    return (EXIT_SUCCESS);
}

/*Probe si funcionaba con gdb y efectivamente funciona.*/