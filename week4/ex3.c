#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXB 1000

char buf[MAXB];

int main(int argc, char *argv[]) {
    while (1) {
        printf("> ");
        fgets(buf, MAXB, stdin);
        if (strcmp(buf, "exit\n") == 0)
            return 0;
        else
            system(buf);
    }

    return 0;
}