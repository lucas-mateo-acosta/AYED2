#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

bool array_is_sorted(int a[], unsigned int length){
    bool sorted = true;
    
    for (unsigned int i=0; i<(length-1); i++){
        sorted = sorted && (a[i]<=a[i+1]);
    }
    return sorted;
}

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    unsigned int length = 0;
    unsigned int count = 0;
    int f = 1;
    FILE *archivo = fopen(filepath, "r");
    fscanf(archivo, "%u", &length);
    assert(length<=max_size);
    if (archivo==NULL){
        printf("Error, the file couldn't be readed\n");
        exit(EXIT_FAILURE);
    }
    while (f!=EOF){
        f = fscanf(archivo, "%d", &array[count]);
        count = count + 1;
    }
    fclose(archivo);
    
    if ((count-1)!=length){
        printf("Error, the actual length of the array is not equal to the length in the file\n");
        exit(EXIT_FAILURE);
    }
    return length;
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    for (unsigned int i=0; i<length; i++){
        if (i!=(length-1)){
            printf("%d, ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
    printf("]\n");
}