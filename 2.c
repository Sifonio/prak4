#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
void test_overflow(int xa, int xb) {
    int num_signed = xa * xb;  
    size_t num_unsigned = (size_t)xa * (size_t)xb;

    printf("xa = %d, xb = %d\n", xa, xb);
    printf("Signed multiplication: %d\n", num_signed);
    printf("Unsigned multiplication: %zu\n", num_unsigned);

    void *ptr = malloc(num_signed);  
    if (ptr == NULL) {
        printf("malloc failed for signed result\n");
    } else {
        printf("malloc succeeded for signed result!\n");
        free(ptr);
    }

    ptr = malloc(num_unsigned);  
    if (ptr == NULL) {
        printf("malloc failed for unsigned result\n");
    } else {
        printf("malloc succeeded for unsigned result!\n");
        free(ptr);
    }
}
int main() {
    test_overflow(100000, 100000); 
    test_overflow(INT_MAX, 2);      
    return 0;
}
//gcc -Wall 2.c -o 2