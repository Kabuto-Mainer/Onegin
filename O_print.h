#ifndef O_PRINT_H
#define O_PRINT_H

#include "O_const.h"


void prt_head_rap_file(FILE* file_address);
void prt_head_wiki_file(FILE* file_address);

void prt_to_consol(all_inf_struct* struct_address);
void prt_to_file(all_inf_struct* struct_address, FILE* file_address);
void prt_orig_to_file(all_inf_struct* struct_address, FILE* file_address);

void prt_space_to_file(FILE* file_address);







#endif // O_PRINT_H
