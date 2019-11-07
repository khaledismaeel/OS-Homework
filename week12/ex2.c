#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 10

char buf[BUFFER_SIZE];

int main(int argc, char *argv[]) {
    int app_flg = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (strcmp(argv[i], "-a") == 0)
                app_flg = O_APPEND;
            else {
                fprintf(stderr, "Unknown option: %s\n", argv[i]);
                exit(1);
            }
        }
    }

    int out[argc];
    out[0] = STDOUT_FILENO;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            out[i] = open(argv[i], O_WRONLY | O_CREAT | app_flg, S_IRUSR | S_IWUSR);
            if (out[i] == -1) {
                fprintf(stderr, "Error opening file \"%s\". Error code: %d\n", argv[i], errno);
                exit(2);
            }
        }
        else
            out[i] = -1;
    }

    int rd;
    while ((rd = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < argc; i++) {
            if (out[i] == -1)
                continue;
            int code = write(out[i], buf, rd);
            if (code != rd) {
                fprintf(stderr, "Error writing to file \"%s\". Error code: %d\n", argv[i], errno);
                exit(3);
            }
        }
    }
    if (rd == -1) {
        fprintf("Error reading from stdin. Error code: %d\n", errno);
        exit(4);
    }

    for (int i = 1; i < argc; i++) {
        if (out[i] != -1) {
            int code = close(out[i]);
            if (code == -1) {
                fprintf(stderr, "Error closing file \"%s\". Error code: %d\n", argv[i], errno);
                exit(5);
            }
        }
    }
    return 0;
}