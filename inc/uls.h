#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

typedef struct s_flags {
    int a;
    int f;
    int l;
    int one;
    int R;
    int A;
    int G;
    int h;
    int dog;
    int e;
    int T;
    int C;
    int F;
    int m;
    int p;
    int r;
    int t;
    int u;
    int c;
    int S;
} t_flags;

t_list **mx_parsing(int i, int argc, char **argv, t_flags *true_flags);
t_list **mx_usage_error(int argc, char **argv, char *usage_flags);
void mx_select_flags(t_flags *true_flags, char flag);
void mx_check_flags_first(t_list **parser, t_flags *true_flags);
void mx_check_flags_second(t_list **parser, t_flags *true_flags);

#endif
