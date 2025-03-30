#include <stdio.h>
#include <stdlib.h>
int main() {
    size_t large_size = (size_t)-1;
    void *ptr = malloc(1024); 
    
    if (!ptr) {
        printf("Помилка виділення пам'яті");
        return 0;
    }

    printf("Успіх виділення пам'яті\n");
    void *new_ptr = realloc(ptr, large_size);

    if (!new_ptr) {
        printf("помилка релоку\n");
        printf("new_ptr: %p\n", (void *)ptr);
        free(ptr);
    } else {
        // Це малоймовірно, оскільки запитуваний розмір надто великий
        printf("Успіх\n");
        free(new_ptr);
    }
    return 0;
}
//gcc -Wall 5.c -o 5
