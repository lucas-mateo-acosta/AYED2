#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){
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

elem pair_first(pair_t p){
    assert(sizeof(pair_t)==sizeof(p));
    int x = p -> fst;
    assert(p->fst==x);
    return x;
}

elem pair_second(pair_t p){
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

