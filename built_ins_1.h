#ifndef BUILT_INS_1_H
#define BUILT_INS_1_H

#include "shell.h"

int unset_alias(info_t *info, char *str);
int input_buf(info_t *info, char **buf, size_t *len);

#endif /* BUILT_INS_1_H */
