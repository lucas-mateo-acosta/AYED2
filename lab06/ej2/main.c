#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(void){
    string string1 = string_create("Abanico");
    string string2 = string_create("Abanderado");
    string string3 = string_create("Banana");
    string string4 = string_create("Hola");
    string string5 = string_create("Arma");
    string string6 = string_create("Armamento");
    string string7 = string_create("Abanico");
    printf("Abanico es menor alfabeticamente que abanderado? %d\n", string_less(string1, string2));
    printf("Abanderado es menor alfabeticamente que abanico? %d\n", string_less(string2, string1));
    printf("Arma es menor alfabeticamente que armamento? %d\n", string_less(string5, string6));
    printf("Arma es menor alfabeticamente que banana? %d\n", string_less(string5, string3));
    printf("Abanico es igual a abanico? %d\n", string_eq(string1, string7));
    printf("Hola es igual a hola? %d\n", string_eq(string4, string4));
    printf("Banana es igual a hola? %d\n", string_eq(string3, string4));
    return 0;
}
