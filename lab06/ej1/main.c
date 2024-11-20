/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
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

    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    unsigned int i = 0u;
    while (i!=7){
        printf("Elija un numero del 1 al 7 con:\n");
        printf("1. Mostrar árbol por pantalla\n");
        printf("2 . Agregar un elemento\n");
        printf("3 . Eliminar un elemento\n");
        printf("4 . Chequear existencia de elemento\n");
        printf("5 . Mostrar longitud del árbol\n");
        printf("6 . Mostrar raiz, máximo y mínimo del árbol\n");
        printf("7 . Salir\n");
        scanf("%u", &i);

        if (i==1){
           printf("\n");
           if (abb_is_empty(tree)){
              printf("Arbol vacio");
           } else {
              abb_dump(tree);  
           }
           printf("\n\n"); 
        } else if (i==2){
            unsigned int e = 0u;
            printf("Elija un numero entero positivo para agregar: \n");
            scanf("%u", &e);
            tree = abb_add(tree, e);
        } else if (i==3){
            unsigned int e = 0u;
            printf("Elija el elemento del arbol que desea quitar: \n");
            scanf("%u", &e);
            tree = abb_remove(tree, e);
        } else if (i==4){
            unsigned int e = 0u;
            printf("Elija el elemento a verificar si esta en el arbol: \n");
            scanf("%u", &e);
            bool b = abb_exists(tree, e);
            if (b==true){
                printf("El elemento %u esta en el arbol\n", e);
                printf("\n");
            } else {
                printf("El elemento %u no esta en el arbol\n", e);
                printf("\n");
            }
        } else if (i==5){
            printf("Tiene %u elementos.\n", abb_length(tree));
        } else if (i==6){
            if (!abb_is_empty(tree)) {
                printf("\n");
                printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                            abb_min(tree),
                                                            abb_max(tree));
                printf("\n");
            } else {
                printf("\nÁrbol vacío\n");
            }
        }
    }

    tree = abb_destroy(tree);
    
    return (EXIT_SUCCESS);
}
