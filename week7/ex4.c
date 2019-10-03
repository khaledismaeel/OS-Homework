#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc2(void *ptr, size_t new_size, size_t old_size) {
    void *ret = malloc(new_size);
    if (ret == NULL)
        return NULL;
    memcpy(ret, ptr, (new_size < old_size) ? new_size : old_size);
    free(ptr);
    return ret;
}

int main() {

    return 0;
}