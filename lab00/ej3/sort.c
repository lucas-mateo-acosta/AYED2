#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = izq;
    unsigned int i = izq+1;
    unsigned int j = der;
    while (i<=j){
        if (goes_before(a[i],a[pivot])){
            i = i + 1;
        }
        else if (goes_before(a[pivot],a[j])){
            j = j - 1;
        }
        else {
            swap(a,i,j);
            i = i + 1;
            j = j - 1;
        }
    }
    swap(a,j,pivot);
    pivot = j;
    return pivot;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;
    if (izq<der){
        ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, ppiv);
        quick_sort_rec(a, ppiv+1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

