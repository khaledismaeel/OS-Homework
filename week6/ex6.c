#define _XOPEN_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    printf("Parent process is about to create first fork...\n");
    pid_t pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1 created... waiting to read pid of child 2\n");
        close(fd[1]);
        int sib;
        for (char rd; read(fd[0], &rd, 1) > 0;)
            sib *= 10, sib += rd - '0';
        printf("Child 2 pid read... going to kill after 2 seconds...\n");
        sleep(2);
        printf("Killing child 2...\n");
        kill(sib, SIGSTOP);
        printf("Child 2 killed\n");
    } else {
        printf("parent process is about to create second fork...\n");
        pid_t pid2 = fork();
        if (pid2 == 0) {
            printf("Child 2 created... gonna loop forever...");
            close(fd[0]);
            close(fd[1]);
            while (1)
                ;
        } else {
            close(fd[0]);

            char buf[10];
            memset(buf, 0, sizeof buf);
            sprintf(buf, "%d", pid2);

            printf("Parent process is about to write pid of child 2 to pipe...\n");

            write(fd[1], buf, strlen(buf));
            close(fd[1]);

            printf("Done writing... waiting for child 2...\n");

            int status;
            waitpid(pid2, &status, WUNTRACED);
            printf("Done waiting for child 2... RIP...\n");
        }
    }

    return 0;
}
