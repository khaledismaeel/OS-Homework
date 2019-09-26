#define _XOPEN_SOURCE
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

void handler(int signum) {
    printf("\nI can handle the signal, but for now I'll just quit...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    struct sigaction sigact;
    memset(&sigact, 0, sizeof sigact);
    sigact.sa_handler = &handler;
    
    sigaction(SIGINT, &sigact, NULL);
    
    while (1);


    return 0;
}