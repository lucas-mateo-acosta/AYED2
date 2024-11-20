#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

void swap(fixstring a[], unsigned int i, unsigned int j) {
    fstring_swap(a[i],a[j]);
}

bool goes_before(fixstring x, fixstring y) {
    unsigned int i = 0;
    while (x[i]!='\0' && y[i]!='\0' && !(x[i]>y[i])){
        if (x[i]<y[i]){
            return true;
        }
        i = i + 1;
    }
    if (x[i]=='\0'){
        return true;
    }
    return false;
}

bool array_is_sorted(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}

