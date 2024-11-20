#include <assert.h>
#include <stdio.h>
#include "pair.h"

pair_t pair_new(int x , int y){
    pair_t p;
    p.fst = x;
    p.snd = y;
    assert(p.fst==x && p.snd==y);
    return p;
}

int pair_first(pair_t p){
    assert(sizeof(pair_t)==sizeof(p));
    int x = p.fst;
    assert(x==p.fst);
    return x;
}

int pair_second(pair_t p){
    assert(sizeof(pair_t)==sizeof(p));
    int y = p.snd;
    assert(y==p.snd);
    return y;
}

pair_t pair_swapped(pair_t p){
    assert(sizeof(pair_t)==sizeof(p));
    pair_t q;
    q.fst = p.snd;
    q.snd = p.fst;
    assert(q.fst==p.snd && q.snd==p.fst);
    return q;
}

pair_t pair_destroy(pair_t p){
    return p;
}

/*La implementacion no logra encapsulamiento pues el tipo pair_t esta implementado(definido) en el archivo .h(osea en la
especificacion) por lo que el usuario que quiera usar el TAD podra libremente, en vez de usar solo las operaciones y
constructores del TAD, usar directamente las operaciones que definen al tipo struct en C*/
