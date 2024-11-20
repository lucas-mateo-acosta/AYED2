/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000


unsigned int array_from_stdin(int array[],
                             unsigned int max_size) 
{
    unsigned int length;
    printf("Enter the length of the array\n");
    scanf("%u", &length);
    unsigned int count = 0;
    for (unsigned int i=0; i<max_size; i++){
        if (count<length){
            printf("Enter the element of the array number %u\n", i);
            scanf("%d", &array[i]);
            count = count + 1;
        }
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

int main(void) {
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
