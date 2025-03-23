#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SMALL_SIZE 1024          // 1 кілобайт
#define LARGE_SIZE 1024 * 1024 * 100 // 100 мегабайтів

void test(size_t size) {
    clock_t start, end;
    void *ptr;
    start = clock();
    ptr = malloc(size);
    if (!ptr) {
        printf("помилка виділення пам'яті для: %zu байтів\n", size);
        return;
    }
    for (size_t i = 0; i < size; i += 4096) {
        ((char*)ptr)[i] = 0;
    }
    end = clock();
    printf("Виділено %zu байтів за %lf секунд\n", size, (double)(end - start) / CLOCKS_PER_SEC);
    free(ptr);
}

int main() {
    printf("Перевірка маленької кількості пам'яті:\n");
    test(SMALL_SIZE);

    printf("\nПеревірка великої кількості пам'яті:\n");
    test(LARGE_SIZE);
    return 0;
}
//gcc -Wall 8.c -o 8