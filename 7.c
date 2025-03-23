#include <stdlib.h>
int main(){
    struct sbar *ptr, *newptr;
    ptr = calloc(1000, sizeof(struct sbar));
    newptr = reallocarray(ptr, 500, sizeof(struct sbar));
}
//gcc -Wall 7.c -o 7