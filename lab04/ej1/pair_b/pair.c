#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

pair_t pair_new(int x, int y){
    pair_t p = malloc(sizeof(int)*2);
    if (p==NULL){
        printf("The memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
    p -> fst = x;
    p -> snd = y;
    assert(p->fst==x && p->snd==y);
    return p;
}

int pair_first(pair_t p){
    assert(sizeof(pair_t)==sizeof(p));
    int x = p -> fst;
    assert(p->fst==x);
    return x;
}

int pair_second(pair_t p){
    assert(sizeof(pair_t)==sizeof(p));
    int y = p -> snd;
    assert(p->snd==y);
    return y;
}

pair_t pair_swapped(pair_t p){
    assert(sizeof(pair_t)==sizeof(p));
    pair_t q = malloc(sizeof(int)*2);
    if (q==NULL){
        printf("The memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
    q -> fst = p -> snd;
    q -> snd = p -> fst;
    assert(q->fst==p->snd && q->snd==p->fst);
    return q;
}

pair_t pair_destroy(pair_t p){
    if (p!=NULL){
        free(p);
    }
    return NULL;
}

/*No genera encapsulamiento por lo mismo del inciso anterior. El tipo pair_t esta implementado(definido) como un puntero
a estructura en el archivo h, visible para todos los usuarios por lo que podrian llevar a cabo operaciones directamente
con esa definicion, sin usar las operaciones especificadas.*/