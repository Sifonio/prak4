#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr1 = realloc(NULL, 100);
    if (ptr1 != NULL) {
        printf("realloc(NULL, 100) успіх, ptr1 = %p\n", ptr1);
        free(ptr1);
    } else {
        printf("realloc(NULL, 100) помилка\n");
    }

    void *ptr2 = malloc(50);
    if (ptr2 == NULL) {
        perror("malloc помилка");
        return 1;
    }
    
    void *ptr3 = realloc(ptr2, 0);
    printf("realloc(ptr2, 0) повернуло %p\n", ptr3);
    return 0;
}
//gcc -Wall 6.c -o 6