#include "uls.h"

void mx_check_flags_first(t_list **parser, t_flags *true_flags) {
    if (true_flags->R == 1)
        mx_push_back(&parser[0], "R");
    if (true_flags->a == 1)
        mx_push_back(&parser[0], "a");
    if (true_flags->A == 1)
        mx_push_back(&parser[0], "A");
    if (true_flags->l == 1)
        mx_push_back(&parser[0], "l");
    if (true_flags->C == 0)
        mx_pop_front(&parser[0]);
    if (true_flags->one == 1)
        mx_push_back(&parser[0], "1");
    if (true_flags->m == 1)
        mx_push_back(&parser[0], "m");
    if (true_flags->h == 1)
        mx_push_back(&parser[0], "h");
    if (true_flags->dog == 1)
        mx_push_back(&parser[0], "@");
    if (true_flags->e == 1)
        mx_push_back(&parser[0], "e");
}

void mx_check_flags_second(t_list **parser, t_flags *true_flags) {
    if (true_flags->T == 1)
        mx_push_back(&parser[0], "T");
    if (true_flags->f == 1)
        mx_push_back(&parser[0], "f");
    if (true_flags->r == 1)
        mx_push_back(&parser[0], "r");
    if (true_flags->S == 1)
        mx_push_back(&parser[0], "S");
    if (true_flags->t == 1)
        mx_push_back(&parser[0], "t");
    if (true_flags->u == 1)
        mx_push_back(&parser[0], "u");
    if (true_flags->c == 1)
        mx_push_back(&parser[0], "c");
    if (true_flags->p == 1)
        mx_push_back(&parser[0], "p");
    if (true_flags->F == 1)
        mx_push_back(&parser[0], "F");
    if (true_flags->G == 1)
        mx_push_back(&parser[0], "G");
}
