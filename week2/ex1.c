#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int x = INT_MAX;
    float y = FLT_MAX;
    double z = DBL_MAX;
    printf("x: type int, size %d, value %d\n", (int)(sizeof(x)), x);
    printf("y: type float, size %d, value %f\n", (int)(sizeof(y)), y);
    printf("z: type double, size %d, value %lf\n", (int)(sizeof(z)), z);

    return 0;
}
