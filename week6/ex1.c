#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char msg1[] = "Hello World!";
    char msg2[100];

    int fd[2];
    pipe(fd);

    write(fd[1], msg1, sizeof msg1);
    close(fd[1]);

    char rdc;
    for (int i = 0; read(fd[0], &rdc, 1) > 0; i++)
        msg2[i] = rdc;
    close(fd[0]);

    printf("%s\n", msg2);

    return 0;
}