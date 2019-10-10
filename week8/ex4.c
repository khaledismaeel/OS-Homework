#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    void *ptr[10];
    struct rusage res;

    for (int i = 0; i < 10; i++) {
        ptr[i] = malloc(10 * 1024 * 1024);
        if (ptr[i] != NULL)
            memset(ptr[i], 0, 10 * 1024 * 1024);

        getrusage(RUSAGE_SELF, &res);
        printf("%s: %ld\n", "maximum resident set size", res.ru_maxrss);

        sleep(1);
    }

    for (int i = 0; i < 10; i++)
        free(ptr[i]);
    printf("Memory freed\n");
    getrusage(RUSAGE_SELF, &res);
    printf("%s: %ld\n", "maximum resident set size", res.ru_maxrss);
        
    return 0;
}