#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chk_val(char *str) {
    while (*str != '\0') {
        if (isdigit(*str) == 0)
            return 1;
        str++;
    }
    return 0;
}

void print_rectangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            putchar('*');
        putchar('\n');
    }
}

void print_right(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
}

void print_horizontal(int n) {
    if (n % 2 == 0)
        n++;
    int hor_lim = (n + 1) / 2;
    int cur_width = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cur_width; j++)
            putchar('*');
        putchar('\n');
        if (i < hor_lim - 1)
            cur_width++;
        else
            cur_width--;
    }
}

void print_vertical(int n) {
    int pad = n - 1, cur_width = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < pad; j++)
            putchar(' ');
        for (int j = 0; j < cur_width; j++)
            putchar('*');
        putchar('\n');
        pad--, cur_width += 2;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Size not specified. Exiting.\n");
        return 1;
    }
    if (chk_val(argv[1]) != 0) {
        printf("%s is not a valid integer. Exiting.\n", argv[1]);
        return 2;
    }
    int size = atoi(argv[1]);
    if (argc < 3)
        print_vertical(size);
    else if (strcmp(argv[2], "--vertical") == 0)
        print_vertical(size);
    else if (strcmp(argv[2], "--horizontal") == 0)
        print_horizontal(size);
    else if (strcmp(argv[2], "--rectangle") == 0)
        print_rectangle(size);
    else if (strcmp(argv[2], "--right") == 0)
        print_right(size);
    else {
        printf("Unknown option \"%s\". Exiting.\n", argv[2]);
        return 3;
    }
    return 0;
}
