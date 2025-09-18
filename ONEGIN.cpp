#include <TXLib.h>
#include <stdio.h>
#include <cstdlib>

#include "O_const.h"
#include "O_massive.h"
#include "O_sort.h"
#include "O_support.h"
#include "O_print.h"

int main() { // Test main
    printf("%s\n", NAME_INPUT_FILE);
    printf("%s = %zu bait\n", NAME_INPUT_FILE, file_size_check(NAME_INPUT_FILE));

    FILE* result_file = fop_file(NAME_RESULT_FILE, "w");

    all_inf_struct main_struct = {0, 0,
                                        NULL, NULL};

    if (input_to_buffer(&main_struct) == -1) {
        printf("ERROR\n");
        return 0;
    }
    prt_head_wiki_file(result_file);
    sort_bubble(&main_struct, *compar_bubble_str);
    prt_to_file(&main_struct, result_file);

    prt_head_rap_file(result_file);
    qsort(main_struct.mass_of_struct, main_struct.amount_strings, sizeof(adr_len), &compar_for_qsort_rvs);
    prt_to_file(&main_struct, result_file);

    prt_orig_to_file(&main_struct, result_file);

    free(main_struct.adr_strings);
    fcls_file(result_file);

    return 0;
}





// printf("ADDRESS STRUCT: %p\n", &main_struct);
    // for (size_t i = 0; i < main_struct.amount_strings; i++) {
    //     printf("%s\n", *(main_struct.mass_of_struct[i]));
    // }
    // printf("%s\n", main_struct.mass_of_struct[0]);
    // printf("%c\n", main_struct->adr_strings[0]);
    // free(main_struct->adr_strings);
    // test_strait();

    //      char massive_rectangle[AMOUNT_OF_STRINGS][MAX_LENGTH] = {}; // Test input_onegin_rectangle
    //      input_onegin_rectangle(&(massive_rectangle[0]));
    // const char* str_1 = "######as";
    // const char* str_2 = "xya";

    // printf("%d", who_is_first_strait(str_1, str_2));

    // char bum[10] = {};
    // scanf("%s", bum);
    // printf("%s", bum);

//     FILE* file_address = open_input_file();
//     f_getline_rectangle(file_address, massive_rectangle[0]);
//     f_getline_rectangle(file_address, massive_rectangle[1]); // Test f_getline_rectangle
//
//     printf("%s\n", massive_rectangle[0]);
//     printf("%s\n", massive_rectangle[1]);

    // printf("%s\n", massive_rectangle[1]);
    // input_for_address_with_segmentation_error(&(massive_address[0]));
    // char* massive_address[AMOUNT_OF_STRINGS] = {};
    // input_for_address_with_segmentation_error(massive_address); // Test input_for_address
    // input_for_address_with_segmentation_true(massive_address);

    // printf("%s\n", *(massive_address[2]));











