#include <stdio.h>
#include <stdlib.h>

int main(){
    void *ptr1 = malloc(0);
    void *ptr2 = malloc(3);
    printf("malloc(0): %p \n",ptr1);
    printf("malloc(3): %p",ptr2);
    free(ptr1);
    free(ptr2);
}
//gcc -Wall 3.c -o 3