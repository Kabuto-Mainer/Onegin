#ifndef O_SUPPORT_H
#define O_SUPPORT_H

#define _N_ "\033[1;0m"
#define _R_ "\033[1;31m"
#define _G_ "\033[1;32m"
#define _B_ "\033[1;34m"
#define _P_ "\033[1;35m"
#define _M_ "\033[1;36m"

#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define asrt_to_file(_File_ret_value) {if (_File_ret_value == -1) { \
 printf("%sERROR with file %s %d\n%s", _R_, __FILE__, __LINE__, _N_); \
 exit(1); } \
}
// Дед, не бей
#define asrt_to_file_f(_File_ret_value) {if (_File_ret_value == NULL) { \
 printf("%sERROR with file %s %d\n%s", _R_, __FILE__, __LINE__, _N_); \
 exit(1); } \
 }


size_t file_size_check(const char* name_file);

FILE* fop_file(const char* name_file, const char* type_open);
void fcls_file(FILE* address);

int op_file(const char* name_file, const char* type_open);
int cls_file(int address);


#endif // O_SUPPORT_H
