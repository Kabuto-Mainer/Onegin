#ifndef O_PRINT_H
#define O_PRINT_H

#include "O_const.h"


void print_head_rap_file(FILE* file_address);
void print_head_wiki_file(FILE* file_address);

void print_to_consol(all_inf_struct* struct_address);
void print_to_file(all_inf_struct* struct_address, FILE* file_address);
void print_orig_to_file(all_inf_struct* struct_address, FILE* file_address);

void print_space_to_file(FILE* file_address);

void draw_cat();





#endif // O_PRINT_H
