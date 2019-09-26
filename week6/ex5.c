#define _XOPEN_SOURCE
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
    pid_t pid = fork();
    if (pid == 0) {
        while (1) {
            puts("I am alive!");
            sleep(1);
        }
    }
    else {
        sleep(10);
        kill(pid, SIGKILL);
    }



    return 0;
}