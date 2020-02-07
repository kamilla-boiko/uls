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
    int big_r;
    int big_a;
    int big_g;
    int h;
    int dog;
    int e;
    int big_t;
    int big_c;
    int big_f;
    int m;
    int p;
    int r;
    int t;
    int u;
    int c;
    int big_s;
} t_flags;

t_list **mx_parsing(int i, int argc, char **argv, t_flags *true_flags);
t_list **mx_usage_error(int argc, char **argv, char *usage_flags);
void mx_select_flags(t_flags *true_flags, char flag);
void mx_check_flags_first(t_list **parser, t_flags *true_flags);
void mx_check_flags_second(t_list **parser, t_flags *true_flags);
void mx_select_flags_first(t_flags *true_flags, char flag);
void mx_select_flags_second(t_flags *true_flags, char flag);
void mx_select_flags_third(t_flags *true_flags, char flag);
void mx_select_flags_fourth(t_flags *true_flags, char flag);
void mx_select_flags_fifth(t_flags *true_flags, char flag);
void mx_select_flags_sixth(t_flags *true_flags, char flag);

#endif
