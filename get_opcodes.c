#include <stdio.h>

int main() {
    FILE *ptr = fopen("opcodetest.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    long counters[256] = {0};
    int opcode;
    long opcodeval;
    while (fscanf(ptr, "%d,%ld", &opcode, &opcodeval) == 2) {
        counters[opcode] += opcodeval;
    }
    printf("index,count\n");
    int counters_accessed[256] = {0};
    for (int i = 0; i < 256; i++) {
        int current_highest_index = 0;
        long current_highest = -1;
        for (int ii = 0; ii < 256; ii++) {
            if (counters[ii] > current_highest && counters_accessed[ii] == 0) {
                current_highest_index = ii;
                current_highest = counters[ii];
            }
        }
        counters_accessed[current_highest_index] = 1;
        printf("%d,%ld\n", current_highest_index, counters[current_highest_index]);
    }
    return 0;
}