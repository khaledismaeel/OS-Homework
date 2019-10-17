#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 1000
#define AGE_LIM 32

unsigned int page_frames_count;
unsigned int page_counter[MAX_PAGES]; // using static storage whenever possible.
unsigned int *page_table;
int hits, misses;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr,
                "The number of page frames needs to be passed. Exiting.\n");
        return 1;
    }

    FILE *input = fopen("Lab 09 input.txt", "r");

    if (input == NULL) {
        fprintf(stderr, "Error opening input file. Exiting.\n");
        return 2;
    }

    page_frames_count = atoi(argv[1]);
    page_table = (unsigned int *)calloc(page_frames_count, sizeof(int));

    for (int page; fscanf(input, "%d", &page) == 1;) {
        int found_flag = 0;
        for (int i = 0; i < page_frames_count; i++) {
            if (page == page_table[i]) {
                hits++;
                found_flag = 1;
                break;
            }
        }

        if (found_flag == 0) {
            misses++;
            unsigned int swap_counter = UINT_MAX;
            int swap_index = 0;
            for (int i = 0; i < page_frames_count; i++) {
                unsigned int cand = page_counter[page_table[i]];
                if (cand < swap_counter)
                    swap_counter = cand, swap_index = i;
            }
            page_table[swap_index] = page;
        }

        for (int i = 0; i < MAX_PAGES; i++)
            page_counter[i] >>= 1;
        page_counter[page] |= 1 << (AGE_LIM - 1);
    }

    printf("Total pages read:\t%d\n", hits + misses);
    printf("Total pages hit:\t%d\n", hits);
    printf("Total pages missed:\t%d\n", misses);
    printf("Hit ratio:\t\t%.3f%\n", 100.0 * hits / misses);

    return 0;
}