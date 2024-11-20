#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;
    unsigned int i = 0;
    while (s[i]!='\0'){
        length = length + 1;
        i = i + 1;
    } 
    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    bool res = true;
    if (fstring_length(s1)==fstring_length(s2)){
        while (s1[i]!='\0' && s2[i]!='\0'){
            res = res && (s1[i]==s2[i]);
            i = i + 1;
        }
    }
    else {
        res = false;
    }
    return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    bool res = true;
    bool t = true;
    if (fstring_length(s1)<fstring_length(s2)){
        while (s1[i]!='\0' && t){
            if (s1[i]==s2[i]){
                i = i + 1;
            }
            if (s1[i]<s2[i]){
                t = false;
            }
            if (s1[i]>s2[i]){
                res = false;
                t = false;
            }
        }
    }
    if (fstring_length(s1)>fstring_length(s2)){
        while (s2[i]!='\0' && t){
            if (s1[i]==s2[i]){
                i = i + 1;
            }
            if (s1[i]<s2[i]){
                t = false;
            }
            if (s1[i]>s2[i]){
                res = false;
                t = false;
            }
        }
    }
    if (fstring_length(s1)==fstring_length(s2)){
        while (s1[i]!='\0' && s2[i]!='\0' && t){
            if (s1[i]==s2[i]){
                i = i + 1;
            }
            if (s1[i]<s2[i]){
                t = false;
            }
            if (s1[i]>s2[i]){
                res = false;
                t = false;
            }
        }
    }
    return res;  
}
