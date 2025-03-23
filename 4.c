#include <stdio.h>
#include <stdlib.h>
int main() {
    void *ptr = NULL;
    int i = 0;
    while (i < 3) {
        if (!ptr)
            ptr = malloc(10);
        if (!ptr) {
            printf("Помилка виділення пам'яті\n");
            return 1;
        }
        printf("Ітерація %d, ptr = %p\n", i, ptr);
        free(ptr); 
        i++;
    }
    return 0;
}
//gcc -Wall 4.c -o 4