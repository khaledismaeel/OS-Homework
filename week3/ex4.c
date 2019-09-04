#include <stdio.h>

// Swaps the two integers pointed to by @a and @b.
void swap(int *a, int *b) {
    if (a != b)
        *a ^= *b, *b ^= *a, *a ^= *b;
}

// Helper function for quick_sort.
int *partition(int *begin, int *end) {
    if (end - begin <= 1)
        return begin;
    for (int *j = begin; j != end; j++) {
        if (*j < *(end - 1))
            swap(begin, j), begin++;
    }
    swap(begin, end - 1);
    return begin;
}

// Sorts the integers in [@begin, @end).
// Note that @begin must be <= @end.
void quick_sort(int *begin, int *end) {
    if (end - begin <= 1)
        return;
    int *piv = partition(begin, end);
    quick_sort(begin, piv);
    quick_sort(piv + 1, end);
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    quick_sort(a, a + n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}