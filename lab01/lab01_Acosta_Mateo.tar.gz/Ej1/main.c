/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
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
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
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


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
