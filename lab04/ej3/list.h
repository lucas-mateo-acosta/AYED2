#include <stdbool.h>
#include <stdio.h>

typedef struct Node * list;
typedef int list_elem;

// Constructores

list empty_list();
// {- crea una lista vacía. -}

list addl (list_elem e, list l);
// {- Devuelve la lista resultante de agregar el elemento e al comienzo de la lista l. -}

void destroy (list l);
// {- Libera memoria en caso que sea necesario. -}


// Operaciones

bool is_empty(list l);
// {- Devuelve True si l es vacía. -}

list_elem head(list l);
// {- Devuelve el primer elemento de la lista l -}
// {- PRE: not is_empty(l) -}

list tail(list l);
// {- Devuelve la lista resultante de eliminar el primer elemento de la lista l -}
// {- PRE: not is_empty(l) -}

list addr (list l, list_elem e);
/* {- devuelve la lista resultante de 
    agregar el elemento e al final de la lista l. -}*/

unsigned int length(list l);
// {- Devuelve la cantidad de elementos de la lista l -}

list concat(list l, list l0);
/* {- Devuelve la lista resultante de concatenar l con l0 -}*/
    
list_elem index(list l, unsigned int n);
// {- Devuelve el n-ésimo elemento de la lista l -}
// {- PRE: length(l) > n -}

list take(list l, unsigned int n);
/*  {- Devuelve una lista con los primeros n
    elementos de l, eliminando el resto -}*/

list drop(list l, unsigned int n);
// {- Devuelve una lista sin los primeros n elementos de l -}

list copy_list(list l);
// {- Copia todos los elementos de l en la nueva lista -}