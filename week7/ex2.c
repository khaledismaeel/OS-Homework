#include <stdio.h>
#include <stdlib.h>

int N;

int main() {
    printf("Enter the size: ");
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("memory allocation error. Exiting...\n");
        return 1;
    }
    for (int i = 0; i < N; i++)
        arr[i] = i;
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}