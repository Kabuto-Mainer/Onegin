#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>

#include "O_support.h"
#include "O_const.h"

size_t file_size_check(const char* name_file) {
    assert(name_file);

    struct stat file_stat = {}; //

    if (stat(name_file, &file_stat) == -1) {
        printf("ERROR with stat\n");
        return -1;
    }

    return file_stat.st_size;
}


FILE* fopen_file(const char* name_file, const char* type_open) {
    assert(name_file);

    FILE* buffer = fopen(name_file, type_open);
    asrt_to_file_f(buffer);

    return buffer;
}


void fclose_file(FILE* address) {
    assert(address);

    asrt_to_file( fclose(address) );
}


int close_file(int address) {
    int buffer = close(address);
    asrt_to_file(buffer);

    return buffer;
}


int open_file(const char* name_file, const char* type_open) { // Пока не реализовал в полную силу
    int buffer = open(NAME_INPUT_FILE, O_RDONLY);
    asrt_to_file(buffer);

    return buffer;
}




