#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000



static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path,
                            unsigned int indexes[],
                            char letters[],
                            unsigned int max_size){
                                
    FILE *archivo = fopen(path, "r");
    if (archivo==NULL){
        printf("Error, the file couldn't be readed\n");
        exit(EXIT_FAILURE);
    }
    while (!feof(archivo)){
        fscanf(archivo, "%u ", &indexes[max_size]);
        fscanf(archivo, "-> *%c*", &letters[max_size]);
        max_size = max_size + 1;
    }
    fclose(archivo);
    
    if (max_size>MAX_SIZE){
        printf("Error, the file have more elements than his max length\n");
        exit(EXIT_FAILURE);
    }
    return max_size;
}


int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    if (argc!=2){
        printf("The amount of arguments isn't valid\n");
        exit(EXIT_FAILURE);
    }
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    length = data_from_file(argv[1], indexes, letters, length);

    for (unsigned int i=0; i<length-1; i++){
        printf("%u -> *%c*\n", indexes[i], letters[i]);
        if (indexes[i]>MAX_SIZE){
            printf("Error, the index is bigger than the MAX_SIZE of elements.\n");
            exit(EXIT_FAILURE);
        }
        sorted[indexes[i]] = letters[i];
    }

    fclose(file);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

