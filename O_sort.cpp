#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "O_const.h"
#include "O_sort.h"
#include "O_support.h"

void sort_bubble(all_inf_struct* struct_address, comparison_t compare_function) {
    assert(struct_address);

    adr_len* mass_of_struct = struct_address->mass_of_struct;
    adr_len buffer = {NULL, 0};

    for (size_t i = 0; i < struct_address->amount_strings; i++) {
        for (size_t index = i + 1; index < struct_address->amount_strings; index++) {
            // printf("Index = %zu\n", index);

            if (compare_function(mass_of_struct + i, mass_of_struct + index) > 0) {
                buffer = mass_of_struct[i];
                mass_of_struct[i] = mass_of_struct[index]; // Передача указателей и их разыменовывание будет медленнее
                mass_of_struct[index] = buffer;
            }
        }
        // mass_of_struct[i] = *min_element;
    }
    printf("%sEND\n%s", _M_, _N_);
}


int compar_str(adr_len* struct_1, adr_len* struct_2) {
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
        if (*(struct_1->address + i_1) == '\n') {
            return 1;
        }
        if (*(struct_2->address + i_2) == '\n') {
            return -1;
        }
        if ((difference = toupper(*(struct_1->address + i_1)) - toupper(*(struct_2->address + i_2))) == 0) {
            i_1++;
            i_2++;
            continue;
        }
        return difference;
    }
}


int compar_rvs(adr_len* struct_1, adr_len* struct_2) {
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
        if (*(struct_1->address + i_1) == '\n') {
            return 1;
        }
        if (*(struct_2->address + i_2) == '\n') {
            return -1;
        }
        if ((difference = toupper(*(struct_1->address + i_1)) - toupper(*(struct_2->address + i_2))) == 0) {
            i_1--;
            i_2--;
            continue;
        }
        return difference;
    }
}


int compar_for_qsort_str(const void* input_struct_1, const void* input_struct_2) {
    assert(input_struct_1);
    assert(input_struct_2);

    adr_len* struct_1 = (adr_len*) input_struct_1; // Must be
    adr_len* struct_2 = (adr_len*) input_struct_2; // Must be

    return compar_str(struct_1, struct_2);
}


int compar_for_qsort_rvs(const void* input_struct_1, const void* input_struct_2) {
    assert(input_struct_1);
    assert(input_struct_2);

    adr_len* struct_1 = (adr_len*) input_struct_1;
    adr_len* struct_2 = (adr_len*) input_struct_2;

    return compar_rvs(struct_1, struct_2);
}

// int own_qsort(all_inf_struct* struct_address,
//
//
//
// // Функция сравнения (по длине строки)
// int compareLength(const StringInfo* a, const StringInfo* b) {
//     return a->length - b->length;
// }
//
// // Функция быстрой сортировки без low/high
// StringInfo* quickSortStruct(StringInfo arr[], int size, int* newSize, int (*cmp)(const StringInfo*, const StringInfo*)) {
//     if (size <= 1) {
//         StringInfo* res = (StringInfo*)malloc(size * sizeof(StringInfo));
//         for (int i = 0; i < size; i++) res[i] = arr[i];
//         *newSize = size;
//         return res;
//     }
//
//     StringInfo pivot = arr[size - 1];
//     int leftCount = 0, rightCount = 0;
//
//     // Считаем количество элементов меньше и больше pivot
//     for (int i = 0; i < size - 1; i++) {
//         if (cmp(&arr[i], &pivot) < 0) leftCount++;
//         else rightCount++;
//     }
//
//     StringInfo* left = (StringInfo*)malloc(leftCount * sizeof(StringInfo));
//     StringInfo* right = (StringInfo*)malloc(rightCount * sizeof(StringInfo));
//
//     int l = 0, r = 0;
//     for (int i = 0; i < size - 1; i++) {
//         if (cmp(&arr[i], &pivot) < 0) left[l++] = arr[i];
//         else right[r++] = arr[i];
//     }
//
//     int newLeftSize, newRightSize;
//     StringInfo* sortedLeft = quickSortStruct(left, leftCount, &newLeftSize, cmp);
//     StringInfo* sortedRight = quickSortStruct(right, rightCount, &newRightSize, cmp);
//
//     free(left);
//     free(right);
//
//     // Склеиваем результат
//     *newSize = newLeftSize + 1 + newRightSize;
//     StringInfo* result = (StringInfo*)malloc((*newSize) * sizeof(StringInfo));
//
//     for (int i = 0; i < newLeftSize; i++) result[i] = sortedLeft[i];
//     result[newLeftSize] = pivot;
//     for (int i = 0; i < newRightSize; i++) result[newLeftSize + 1 + i] = sortedRight[i];
//
//     free(sortedLeft);
//     free(sortedRight);
//
//     return result;
// }
//
// // Печать массива структур
// void printArray(StringInfo arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         printf("%s (len=%d)\n", arr[i].addr, arr[i].length);
//     }
// }
//
//


