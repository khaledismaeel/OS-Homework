#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXA 500
#define MAXB 1000

char buf[MAXB];
int argc;
char *argv[MAXA];

void bld_arg(char *s, char *argv[]) {
    char *token = strtok(s, " \n");
    argc = 0;
    while (token) {
        argv[argc++] = token;
        token = strtok(NULL, " \n");
    }
    argv[argc] = NULL;
}

int main() {
    while (1) {
        printf("> ");

        fgets(buf, MAXB, stdin);
        bld_arg(buf, argv);

        if (strcmp(argv[0], "exit") == 0)
            return 0;
        
        int back = 0;
        if (strcmp(argv[argc - 1], "&") == 0)
            back = 1, argv[--argc] = NULL;

        __pid_t pid = fork();
        int status;

        if (pid == 0) {
            execvp(argv[0], argv);
            break;
        } else if (back == 0)
            waitpid(pid, &status, 0);
    }
    return 0;
}