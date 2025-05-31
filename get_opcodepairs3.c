#include <stdio.h>

int main() {
    FILE *ptr = fopen("//opcodepairtest.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    long counters[256][256] = {0};
    long counters2[256][256] = {0};
    int opcode;
    int pairopcode;
    long opcodeval;
    while (fscanf(ptr, "%d,%d,%ld", &opcode, &pairopcode, &opcodeval) == 3) {
        if (opcode < 256 && pairopcode < 256) {
            counters[opcode][pairopcode] += opcodeval;
        }
        if (opcode >= 10000) {
            int opcode2 = opcode-10000;
            if (opcode2 < 256 && pairopcode < 256) {
                counters2[opcode2][pairopcode] += opcodeval;
            }
        }
    }
    for (int counters_ii = 0; counters_ii < 256; counters_ii++) {
        for (int counters_i = 0; counters_i < 256; counters_i++) {
            if(counters[counters_ii][counters_i] > 0) {
                printf("%d,%d,%ld\n",counters_ii,counters_i,counters[counters_ii][counters_i]);
            }
        }
    }
    printf("----------\n");
    for (int counters_ii = 0; counters_ii < 256; counters_ii++) {
        for (int counters_i = 0; counters_i < 256; counters_i++) {
            if(counters2[counters_ii][counters_i] > 0) {
                printf("%d,%d,%ld\n",counters_ii,counters_i,counters2[counters_ii][counters_i]);
            }
    }
    }
}