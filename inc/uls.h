#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

t_list **mx_parsing(int i, int argc, char **argv);
t_list **mx_usage_error(int argc, char **argv);

#endif
