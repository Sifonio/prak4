#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = NULL;
    for (int i = 0; i < 3; i++) {
        if (!ptr)
            ptr = malloc(10); 
        
        if (ptr) {
            printf("Ітерація %d: ptr = %p\n", i, ptr);
            ((char *)ptr)[0] = 'A';  
        }

        free(ptr);  
        ptr = NULL;
    }

    return 0;
}
//gcc -Wall 4.c -o 4
