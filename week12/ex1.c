#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    char buf[20];
    int rnd = open("/dev/random", 0);
    
    read(rnd, buf, 20);
    write(STDOUT_FILENO, buf, 20);

    close(rnd);
    return 0;
}