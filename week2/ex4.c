#include <stdio.h>

void swp(int *a, int *b) {
    // Pro trick: swapping integral variables without a temporary variable using
    // bitwise operations
    *a ^= *b, *b ^= *a, *a ^= *b;
}

int main(int argc, char *argv[]) {
    int x, y;
    printf("Enter two space-separated integers: ");
    scanf("%d %d", &x, &y);
    swp(&x, &y);
    printf("Swapped integers: %d %d\n", x, y);

    return 0;
}
