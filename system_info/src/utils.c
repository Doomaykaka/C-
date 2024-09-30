#include <stdio.h>
#include <string.h>

#include <windows.h>

#include "constants.h"
#include "utils.h"


char* get_arch_name(WORD arch) {
    switch(arch) {
        case 0b0000:
            return "INTEL_86";
        case 0b0101:
            return "ARM_32";
        case 0b0110:
            return "IA_64";
        case 0b1001:
            return "AMD_64";
        case 0b1100:
            return "ARM_64";
    }

    return "Unknown";
}


double bytes_to_gigabytes(DWORDLONG amount) {
    return (double)amount / (double)DIVGB;
}


double get_percent(DWORDLONG part, DWORDLONG total) {
    return (double)part / (double)total * 100;
}


void print_title(char* title) {
    int filler_length = TITLE_WIDTH - strlen(title) - 2;
    int left_filler_length = filler_length / 2;
    int right_filler_length = filler_length - left_filler_length;

    print_char_n_times(TITLE_FILLER_SYMBOL, left_filler_length);
    printf(" %s ", title);
    print_char_n_times(TITLE_FILLER_SYMBOL, right_filler_length);
    printf("\n");
}

void print_char_n_times(char symbol, int times) {
    for (int i = 0; i < times; i++) {
        printf("%c", symbol);
    }
}
