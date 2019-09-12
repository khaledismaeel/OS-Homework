#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int lim = atoi(argv[1]);
    for (int i = 0; i < lim; i++) {
        fork();
        sleep(5);
    }
    return 0;
}