#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "O_const.h"
#include "O_sort.h"

void sort_bubble(all_inf_struct* struct_address, comparison_t compare_function) {
    assert(struct_address);

    adr_len* mass_of_struct = struct_address->mass_of_struct; // TODO: Возможно тут сикфолт
    adr_len buffer = {NULL, 0};

    for (size_t i = 0; i < struct_address->amount_strings; i++) {
        for (size_t index = i + 1; index < struct_address->amount_strings; index++) {
            // printf("Index = %zu\n", index);

            if (compare_function(mass_of_struct + i, mass_of_struct + index) > 0) {
                buffer = mass_of_struct[i];
                mass_of_struct[i] = mass_of_struct[index];
                mass_of_struct[index] = buffer;
            }
        }
        // mass_of_struct[i] = *min_element;
    }
}


int compar_bubble_str(adr_len* struct_1, adr_len* struct_2) {
    assert(struct_1);
    assert(struct_2);

    int difference = 0;
    size_t max_1 = struct_1->length;
    size_t max_2 = struct_2->length;
    size_t i_1 = 0;
    size_t i_2 = 0;

    while (true) {
        while (i_1 < max_1 && !isalpha(*(struct_1->address + i_1))) {
            i_1++;
        }
        while (i_2 < max_2 && !isalpha(*(struct_2->address + i_2))) {
            i_2++;
        }
        if ((difference = toupper(*(struct_1->address + i_1)) - toupper(*(struct_2->address + i_2))) == 0) {
            i_1++;
            i_2++;
            continue;
        }
        return difference;
    }
}


int compar_bubble_rvs(adr_len* struct_1, adr_len* struct_2) {
    assert(struct_1);
    assert(struct_2);

    int difference = 0;
    size_t i_1 = struct_1->length - 1;
    size_t i_2 = struct_2->length - 1;

    while (true) {
        while (i_1 > 0 && !isalpha(*(struct_1->address + i_1))) {
            i_1--;
        }
        while (i_2 > 0 && !isalpha(*(struct_2->address + i_2))) {
            i_2--;
        }
        if ((difference = toupper(*(struct_1->address + i_1)) - toupper(*(struct_2->address + i_2))) == 0) {
            i_1--;
            i_2--;
            continue;
        }
        return difference;
    }
}


int compar_for_qsort_rvs(const void* input_struct_1, const void* input_struct_2) {
    assert(input_struct_1);
    assert(input_struct_2);

    int difference = 0;

    adr_len* struct_1 = (adr_len*) input_struct_1;
    adr_len* struct_2 = (adr_len*) input_struct_2;

    size_t i_1 = struct_1->length - 1;
    size_t i_2 = struct_2->length - 1;

    while (true) {
        while (i_1 > 0 && !isalpha(*(struct_1->address + i_1))) {
            i_1--;
        }
        while (i_2 > 0 && !isalpha(*(struct_2->address + i_2))) {
            i_2--;
        }
        if ((difference = toupper(*(struct_1->address + i_1)) - toupper(*(struct_2->address + i_2))) == 0) {
            i_1--;
            i_2--;
            continue;
        }
        return difference;
    }
}


int compar_for_qsort_rvs(const void* input_struct_1, const void* input_struct_2) {
    assert(input_struct_1);
    assert(input_struct_2);

    int difference = 0;

    adr_len* struct_1 = (adr_len*) input_struct_1;
    adr_len* struct_2 = (adr_len*) input_struct_2;

    size_t i_1 = struct_1->length - 1;
    size_t i_2 = struct_2->length - 1;

    while (true) {
        while (i_1 > 0 && !isalpha(*(struct_1->address + i_1))) {
            i_1--;
        }
        while (i_2 > 0 && !isalpha(*(struct_2->address + i_2))) {
            i_2--;
        }
        if ((difference = toupper(*(struct_1->address + i_1)) - toupper(*(struct_2->address + i_2))) == 0) {
            i_1--;
            i_2--;
            continue;
        }
        return difference;
    }
}


