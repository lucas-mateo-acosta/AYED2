#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str){
    size_t length = 0;
    unsigned int i = 0u;
    while (str[i]!='\0'){
        length = length + 1;
        i = i + 1;
    }
    return length;
}

char *string_filter(const char *str, char c){
    char *result = malloc(sizeof(string_length(str)));
    unsigned int i = 0u;
    unsigned int j = 0u;
    if (str==NULL){
        free(result);
        result=NULL;
    } else {
        while(str[i]!='\0'){
            if (str[i]!=c){
                result[j] = str[i];
                j = j + 1;
            }
            i = i + 1;
        }
    }
    return result;
}