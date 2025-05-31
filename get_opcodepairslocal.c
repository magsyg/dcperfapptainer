#include <stdio.h>

int main() {
    FILE *ptr = fopen("./opcodepairtest.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    long counters[256][256] = {0};
    int opcode;
    int pairopcode;
    long opcodeval;
    while (fscanf(ptr, "%d,%d,%ld", &opcode, &pairopcode, &opcodeval) == 3) {
        counters[opcode][pairopcode] += opcodeval;
    }
    for (int counters_ii = 0; counters_ii < 256; counters_ii++) {
        for (int counters_i = 0; counters_i < 256; counters_i++) {
            if(counters[counters_ii][counters_i] > 0) {
                printf("%d,%d,%ld\n",counters_ii,counters_i,counters[counters_ii][counters_i]);
            }
        }
    }
}