#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    void *ptr[10];
    for (int i = 0; i < 10; i++) {
        ptr[i] = malloc(10 * 1024 * 1024);
        if (ptr[i] != NULL)
            memset(ptr[i], 0, 10 * 1024 * 1024);
        sleep(1);
    }
    // No need to free the memory, it's just good practice.
    for (int i = 0; i < 10; i++)
        free(ptr[i]);
    return 0;
}