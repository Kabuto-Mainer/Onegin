#ifndef DEFINE_CONST_H
#define DEFINE_CONST_H


const char NAME_INPUT_FILE[] = "ONEGIN.txt";
const char NAME_RESULT_FILE[] = "RESULT.txt";
const char NAME_TEST_FILE[] = "O_test_result.txt";

const int SKIP_CHAR = 'в'; // DO NOT CHANGE

const size_t MAX_LENGTH = 100;
const size_t AMOUNT_OF_STRINGS = 5500;
const size_t MAX_SIZE = 1e6;
const int AMOUNT_SPACE = 3;

struct adr_len {
    char* address;
    size_t length;
};

struct all_inf_struct {
    size_t amount_strings;
    size_t max_length;
    char* adr_strings;
    adr_len mass_of_struct[AMOUNT_OF_STRINGS];
};

typedef int (*comparison_t) (adr_len*, adr_len*);
typedef int (*compar_qsort_t) (const void* input_struct_1, const void* input_struct_2);

#endif // DEFINE_CONST_H
