#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *user_input=NULL;
    size_t maxlength = 100;

    user_input = malloc(sizeof(char)*maxlength);
    if (user_input==NULL){
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Ingrese su nombre y apellido: ");
    fgets(user_input, maxlength, stdin);
    size_t size = strlen(user_input);

    user_input[size-1] = '\0';

    printf("Te damos la bienvenida %s a este maravilloso programa!\n", user_input);

    free(user_input);

    return EXIT_SUCCESS;
}

