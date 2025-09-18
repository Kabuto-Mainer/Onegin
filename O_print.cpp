#include <stdio.h>
#include <assert.h>

#include "O_print.h"
#include "O_const.h"


void prt_to_consol(all_inf_struct* struct_address) {
    assert(struct_address);

    for (size_t i = 0; i < struct_address->amount_strings; i++) {
        char* string = struct_address->mass_of_struct[i].address;
        if (*(string) == '\0' || *(string) == '\n') {
            break;
        }
        // printf("poem - %s\n", string);
        for (size_t index = 0; index < struct_address->mass_of_struct[i].length; index++) {
            if (*(string + index) == SKIP_CHAR) {
                index += 2;
                continue;
            }

            putchar(*(string + index));
        }
    }
}


void prt_to_file(all_inf_struct* struct_address, FILE* file_address) {
    assert(struct_address);
    assert(file_address);

    // printf("Amount of strings to write: %zu\n", struct_address->amount_strings);

    for (size_t i = 0; i < struct_address->amount_strings; i++) {
        char* string = struct_address->mass_of_struct[i].address;

        if (*(string) == '\0'/* || *(string) == '\n'*/) {
            break;
        }

        for (size_t index = 0; index < struct_address->mass_of_struct[i].length; index++) {
            if (*(string + index + 1) == SKIP_CHAR) {
                index += 2;
                continue;
            }

            fputc(*(string + index), file_address);
        }
    }
}


void prt_head_rap_file(FILE* file_address) {
    assert(file_address);

    prt_space_to_file(file_address);
    fprintf(file_address, "----------This is text of poem Evgeny Onegin in version for rappers-------------\n");
    prt_space_to_file(file_address);
}


void prt_head_wiki_file(FILE* file_address) {
    assert(file_address);

    fprintf(file_address, "----------This is text of poem Evgeny Onegin in version WIKI-------------\n");
    prt_space_to_file(file_address);
}


void prt_orig_to_file(all_inf_struct* struct_address, FILE* file_address) {
    assert(struct_address);
    assert(file_address);

    prt_space_to_file(file_address);
    fprintf(file_address, "----------This is the original text of poem Evgeny Onegin-----------\n");
    prt_space_to_file(file_address);

    fputs(struct_address->adr_strings, file_address);
}


void prt_space_to_file(FILE* file_address) {
    assert(file_address);

    for (int i = 0; i < AMOUNT_SPACE; i++) {
        fprintf(file_address, "                                                                                                   \n");
    }
}
