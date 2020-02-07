#include "uls.h"

void mx_select_flags(t_flags *true_flags, char flag) {
    switch(flag) {
    	//1 group (a/A)
        case 'a':
            true_flags->a = 1;
            true_flags->A = 0;
            break ;
        case 'A':
            true_flags->A = 1;
            if (true_flags->a == 1) 
                true_flags->A = 0;
            break ;
        //2 group (1/C/l/m)
        case 'l':
            true_flags->l = 1;
            true_flags->C = 0;
            true_flags->one = 0;
            true_flags->m = 0;
            break ;
        case '1':
            true_flags->one = 1;
            true_flags->C = 0;
            true_flags->l = 0;
            true_flags->m = 0;
            break ;
        case 'm':
            true_flags->m = 1;
            true_flags->C = 0;
            true_flags->one = 0;
            true_flags->l = 0;
            break ;
        case 'C':
            if (true_flags->m != 1) {
                true_flags->C = 1;
                true_flags->l = 0;
                true_flags->one = 0;
            }
            break ;
        //3 group (h/@/e/T)
        case 'h':
            if (true_flags->l == 1)
                true_flags->h = 1;
            break ;
        case '@':
            if (true_flags->l == 1)
                true_flags->dog = 1;
            break ;
        case 'e':
            if (true_flags->l == 1)
                true_flags->e = 1;
            break ;
        case 'T':
            if (true_flags->l == 1)
                true_flags->T = 1;
            break ;
        //4 group (f/r/t/S)
        case 'f':
            true_flags->f = 1;
            true_flags->a = 1;
            true_flags->A = 0;
            true_flags->r = 0;
            true_flags->t = 0;
            true_flags->S = 0;
            break ;
        case 'r':
            if (true_flags->f != 1)
                true_flags->r = 1;
            break ;
        case 't':
            if (true_flags->S != 1 && true_flags->f != 1)
                true_flags->t = 1;
            break ;
        case 'S':
            if (true_flags->f != 1) {
                true_flags->S = 1;
                true_flags->t = 0;
            }
            break ;
        //5 group (c/u)
        case 'c':
            true_flags->c = 1;
            true_flags->u = 0;
            break ;
        case 'u':
            true_flags->u = 1;
            true_flags->c = 0;
            break ;
        //6 group (F/p)
        case 'F':
            true_flags->F = 1;
            true_flags->p = 0;
            break ;
        case 'p':
            true_flags->p = 1;
            true_flags->F = 0;
            break ;
        //7 group - single (R/G)
        case 'R':
            true_flags->R = 1;
            break ;
        case 'G':
            true_flags->G = 1;
            break ;
    }
}
