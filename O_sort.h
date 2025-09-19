#ifndef DEFINE_SORT_H
#define DEFINE_SORT_H

int compar_bubble_str(adr_len* struct_1, adr_len* struct_2);
int compar_bubble_rvs(adr_len* struct_1, adr_len* struct_2);

int compar_for_qsort_rvs(const void* input_struct_1, const void* input_struct_2);
int compar_for_qsort_str(const void* input_struct_1, const void* input_struct_2);

void sort_bubble(all_inf_struct* address_struct, comparison_t compare_function);

#endif // DEFINE_SORT_H
