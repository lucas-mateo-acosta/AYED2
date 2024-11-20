/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* create a copy of the array */
    int copy[MAX_SIZE];
    array_copy(copy, array, length);

    /* reset counters and set time */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();

    /* do the actual sorting */
    selection_sort(copy, length);

    /* show statistics for selection_sort */
    printf("statistics for selection_sort\n");
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());

    /* create a copy of the array */
    int copy1[MAX_SIZE];
    array_copy(copy1, array, length);

    /* reset counters and set time */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();

    /* do the actual sorting */
    insertion_sort(copy1, length);

    /* show statistics for insertion_sort */
    printf("statistics for insertion_sort\n");
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());

    /* create a copy of the array */
    int copy2[MAX_SIZE];
    array_copy(copy2, array, length);

    /* reset counters and set time */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();

    /* do the actual sorting */
    quick_sort(copy2, length);

    /* show statistics for quick_sort */
    printf("statistics for quick_sort\n");
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());



    return EXIT_SUCCESS;
}


/* Para el ejemplo example-unsorted.in, que es un arreglo de 5 elementos obtuvimos:
   SELECTION SORT:
    tiempo transcurrido: 0.023 , comparaciones: 10 , intercambios(swap): 5
   INSERTION SORT:
    tiempo transcurrido: 0.015 , comparaciones: 7 , intercambios(swap): 5 
   QUICK SORT:
    tiempo transcurrido: 0.016 , comparaciones: 14 , intercambios(swap): 6
   
   Para el ejemplo example-sorted.in, que es un arreglo de 5 elementos obtuvimos:
   SELECTION SORT:
    tiempo transcurrido: 0.018 , comparaciones: 10 , intercambios(swap): 5
   INSERTION SORT:
    tiempo transcurrido: 0.013 , comparaciones: 4 , intercambios(swap): 0 
   QUICK SORT:
    tiempo transcurrido: 0.013 , comparaciones: 20 , intercambios(swap): 4
    (aunque el quick sort varia mucho , a veces es el que mas tarda mientras que
    otras veces es el que menos tarda junto con el insertion, que es el que menos
    tarda siempre pues hace menos comparaciones que los demas y cero intercambios)
   
   Para el ejemplo all-positive-100.in, que es un arreglo de 100 elementos obtuvimos:
   SELECTION SORT:
    tiempo transcurrido: 0.123 , comparaciones: 4950 , intercambios(swap): 100
   INSERTION SORT:
    tiempo transcurrido: 0.103 , comparaciones: 2863 , intercambios(swap): 2770 
   QUICK SORT:
    tiempo transcurrido: 0.041 , comparaciones: 987 , intercambios(swap): 207
    (vemos que para arreglos de mayor magnitud se nota la diferencia de tiempo 
    en el quick sort, siendo este el que menos tarda con la menor cantidad de 
    comparaciones entre los tres. El selection y el insertion van variando, estan
    mas cerca en tiempo pues tienen similar cantidad de operaciones entre swap y
    comparaciones, pero en gral tarda un poco mas el selection).
    
    De todas maneras en conclusion general, el quick sort se mantiene en los ejemplos
    con cantidad de tiempo transcurrido pequeña, y en algunos casos es similar la situacion
    del insertion, mientras que en gral el selection es el que tarda mas. */
