#include <stdio.h>

// Sorts the integer array in the range [@begin, @end)
// Note that @begin must be <= @end.
void bubble_sort(int *begin, int *end) {
    int flg = 1;
    while (flg == 1) {
        flg = 0;
        for (int *i = begin, *j = begin + 1; j < end; i++, j++)
            if (*i > *j)
                *i ^= *j, *j ^= *i, *i ^= *j, flg = 1;
    }
}
int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    bubble_sort(a, a + n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}