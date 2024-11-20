#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct Node {
    list_elem elem;
    struct Node *next;
};

list empty_list(){
    return NULL;
}

list addl (list_elem e, list l){
    list l0 = malloc(sizeof(struct Node));
    if (l0==NULL){
        printf("Error, the memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
    l0 -> elem = e;
    l0 -> next = l;
    return l0;
}

void destroy (list l){
    while (l!=NULL){
        list l0 = l;
        l = l -> next;
        free(l0);
    }
}

bool is_empty(list l){
    return l==NULL;
}

list_elem head(list l){
    assert(l!=NULL);
    list_elem e = 0;
    e = l -> elem;
    return e;
}

list tail(list l){
    assert(l!=NULL);
    list l0 = malloc(sizeof(struct Node));
    if (l0==NULL){
        printf("Error, the memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
    l0 = l -> next;
    free(l);
    return l0;
}

list addr (list l, list_elem e){
    list l0 = l;
    while (l0->next!=NULL){
        l0 = l0 -> next;
    }
    list l1 = malloc(sizeof(struct Node));
    l1 -> elem = e;
    l1 -> next = NULL;
    l0 -> next = l1;
    free(l1);
    return l;
}

unsigned int length(list l){
    unsigned int length = 0u;
    list l0 = l;
    while (l0!=NULL){
        l0 = l0 -> next;
        length = length + 1;
    }
    return length;
}

list concat(list l, list l0){
    list p = l;
    if (p==NULL){
        return l0;
    }
    while (p!=NULL){
        p = p -> next;
    }
    p = l0;
    return l;
}

list_elem index(list l, unsigned int n){
    assert(length(l)>n);
    list p = l;
    list_elem e = 0;
    for (unsigned int i = 0u; i<n; i++){
        p = p -> next;
    }
    e = p -> elem;
    return e;
}

list take(list l, unsigned int n){
    if (l!=NULL){
        list p = l;
        for (unsigned int i=0u; i<n+1; i++){
            p = p ->next;
        }
        list p1 = p;
        list p2 = p;
        while (p2->next!=NULL){
            p1 = p1 -> next;
            p2 = p1 -> next;
            free(p1);
        }
        free(p);
        free(p2);
    }
    return l;
}

list drop(list l, unsigned int n){
    if (l!=NULL){
        for (unsigned int i=0u; i<n+1; i++){
            list p = l;
            free(p);
            l = l -> next;
        }
    }
    return l;
}

list copy_list(list l){
    list l0 = l;
    return l0;
}