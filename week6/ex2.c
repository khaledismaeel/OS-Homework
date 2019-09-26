#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    char msg1[] = "Hello World!";
    char msg2[100];

    int fd[2];
    pipe(fd);

    int pid = fork();
    
    if (pid == 0) {
        close(fd[1]);
        char rdc;
        for (int i=0;read(fd[0], &rdc, 1) > 0; i++)
            msg2[i] = rdc;
        printf("Reading message \"%s\" from child\n", msg2);
        close(fd[0]);
    }
    else {
        close(fd[0]);
        printf("Printing message \"%s\"from parent\n", msg1);
        write(fd[1], msg1, sizeof msg1);
        close(fd[1]);
    }
    return 0;
}