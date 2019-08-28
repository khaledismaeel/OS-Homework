#include <stdio.h>
#include <string.h>

#define BUF_SIZE (1 << 10)

char buf[BUF_SIZE];

int main(int argc, char *argv[]) {
    printf("Enter a string of size at most %d: ", BUF_SIZE - 1);
    scanf("%s", buf);
    printf("Reversed string: ");
    int idx = strlen(buf);
    while (idx > 0)
        idx--, putchar(buf[idx]);
    putchar('\n');

    return 0;
}
