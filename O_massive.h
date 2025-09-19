#ifndef DEFINE_MASSIVE_H
#define DEFINE_MASSIVE_H

#include "O_const.h"

size_t input_onegin_rectangle(char buffer[][MAX_LENGTH]);
size_t input_for_address_with_segmentation_error(char* massive_of_address[AMOUNT_OF_STRINGS]);
size_t input_for_address_with_segmentation_true(char* massive_of_address[AMOUNT_OF_STRINGS]);
size_t f_getline_e(FILE* file_address, char buffer[MAX_LENGTH]);

int input_to_buffer(all_inf_struct* struct_address);

char* create_buffer();
size_t find_chr(char* string, const char symbol);
size_t pass_space(char* string_place, size_t index);






#endif // DEFINE_MASSIVE_H
