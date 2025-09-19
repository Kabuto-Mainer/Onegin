#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

//#include "O_test.h"
#include "O_const.h"
#include "O_massive.h"
#include "O_support.h"

size_t input_onegin_rectangle(char buffer[][MAX_LENGTH]) {
    assert(buffer);

    FILE* file_address = fop_file(NAME_INPUT_FILE, "r");

    size_t counter = 0;

    while (true) {
        if (f_getline_e(file_address, buffer[counter])) {
            printf("%s\n", buffer[counter]);
        }
        else {
            break;
        }
        counter++;
    }
    fcls_file(file_address);
    return counter++;
}


size_t input_for_address_with_segmentation_error(char* massive_of_address[AMOUNT_OF_STRINGS]) { // Ошибки не вышло
    assert(massive_of_address);

    FILE* file_address = fop_file(NAME_INPUT_FILE, "r");

    size_t counter = 0;
    char buffer[MAX_LENGTH] = {};
    // printf("%p", buffer);

    while (true) {
        if (f_getline_e(file_address, buffer)) {
            massive_of_address[counter] = buffer;
        }
        else {
            break;
        }
        counter++;
    }
    fcls_file(file_address);
    return counter;
}


size_t input_for_address_with_segmentation_true(char* massive_of_address[AMOUNT_OF_STRINGS]) {
    assert(massive_of_address);

    FILE* file_address = fop_file(NAME_INPUT_FILE, "r");

    size_t counter = 0;
    char buffer[MAX_LENGTH] = {};

    while (true) {
        if (f_getline_e(file_address, buffer)) {
            massive_of_address[counter] = strdup(buffer);
        }

        else {
            break;
        }
        counter++;
    }
    fcls_file(file_address);
    return counter;
}


size_t f_getline_e(FILE* file_address, char buffer[MAX_LENGTH]) {
    assert(file_address);
    assert(buffer);

    char symbol = '\0';
    size_t  i = 0;

    while (isspace(symbol = fgetc(file_address))) {
        continue;
    }

    while (true) {

        if (symbol == '\n' || symbol == EOF) {
            break;
        }
        buffer[i] = symbol;
        i++;
        symbol = fgetc(file_address);
    }
    buffer[i] = '\0';
    return i;
}


int input_to_buffer(all_inf_struct* struct_address) {
    char* string_place = crt_buffer();
    int file_address = op_file(NAME_INPUT_FILE, "r");

    size_t amount_symbols = read(file_address, string_place, sizeof(char) * (MAX_SIZE + 1)); // Возможно стоит создать буфер с точным размером
    string_place[amount_symbols] = '\0';

    size_t counter = 0;
    size_t max_len = 0;

    for (size_t i = 0; i < amount_symbols; ) {

        if (counter >= AMOUNT_OF_STRINGS) {
            return -1;
            // break;
        }

        struct_address->mass_of_struct[counter].address = string_place + i;
        size_t buffer_len = 0;

        buffer_len = fnd_chr(string_place + i, '\n');

        if (buffer_len < 1) {
            break;
        }

        struct_address->mass_of_struct[counter].length = buffer_len;
        counter++;
        i += buffer_len;

        if (buffer_len > max_len) {
            max_len = buffer_len;
        }
    }
    struct_address->amount_strings = counter;
    struct_address->max_length = max_len;
    struct_address->adr_strings = string_place;

    cls_file (file_address);
    return 0;
}


size_t fnd_chr (char* string, const char symbol) {
    assert(string);

    if (*(string) == symbol) {
        return 1;
    }
    for (size_t i = 0; ; i++) {
        if (*(string + i) == symbol) {
            // printf("Len - %zu\n", i + 1);
            return i + 1;
        }
        if (*(string + i) == '\0') {
            return 0;
        }
        if (*(string + i) == SKIP_CHAR) {
            *(string + i) = '\'';
            *(string + i + 1) = ' ';
            *(string + i + 2) = ' ';
            i += 2;
        }
    }
    return 0;
}


size_t pass_space(char* string_place, size_t index) {
    assert(string_place);

    while (string_place[index] == ' ' || string_place[index] == '\t') {
        index++;
    }
    return index;
}


char* crt_buffer() {
    char* buffer_address = (char*) calloc(MAX_SIZE + 1, sizeof(char));

    if (buffer_address == NULL) {
        printf("ERROR with calloc in true_input\n");
        return NULL;
    }

    return buffer_address;
}

