#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if (x>=0){
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    a = -10;
    absolute(a, &res);
    printf("%d\n", res);
    return EXIT_SUCCESS;
}

/* int *y seria un parametro out pues es usada solamente para devolver un valor a la salida.

¿¿¿ Al ser puntero debe funcionar como out pues se modifica la informacion en una direccion de memoria especifica
en donde tenia guardado un valor entero previamente por otro, entonces si despues yo uso esa variable entera 
tendra el valor nuevo pues sigue siendo la misma direccion de memoria ??? */

/* Parametros in (pues en proc1 se vio), parametros in/out pues depende segun el contexto del proc o de la funcion, y
parametros out como en este caso. */