#include "uls.h"

void mx_select_flags(t_flags *trueFlags, char flag) {
    switch(flag) {
    	//1 group (a/A)
        case 'a':
            trueFlags->a = 1;
            trueFlags->A = 0;
            break ;
        case 'A':
            trueFlags->A = 1;
            if (trueFlags->a == 1) 
                trueFlags->A = 0;
            break ;
        //2 group (1/C/l/m)
        case 'l':
            trueFlags->l = 1;
            trueFlags->C = 0;
            trueFlags->one = 0;
            trueFlags->m = 0;
            break ;
        case '1':
            trueFlags->one = 1;
            trueFlags->C = 0;
            trueFlags->l = 0;
            trueFlags->m = 0;
            break ;
        case 'm':
            trueFlags->m = 1;
            trueFlags->C = 0;
            trueFlags->one = 0;
            trueFlags->l = 0;
            break ;
        case 'C':
            if (trueFlags->m != 1) {
                trueFlags->C = 1;
                trueFlags->l = 0;
                trueFlags->one = 0;
            }
            break ;
        //3 group (h/@/e/T)
        case 'h':
            if (trueFlags->l == 1)
                trueFlags->h = 1;
            break ;
        case '@':
            if (trueFlags->l == 1)
                trueFlags->dog = 1;
            break ;
        case 'e':
            if (trueFlags->l == 1)
                trueFlags->e = 1;
            break ;
        case 'T':
            if (trueFlags->l == 1)
                trueFlags->T = 1;
            break ;
        //4 group (f/r/t/S)
        case 'f':
            trueFlags->f = 1;
            trueFlags->a = 1;
            trueFlags->A = 0;
            trueFlags->r = 0;
            trueFlags->t = 0;
            trueFlags->S = 0;
            break ;
        case 'r':
            if (trueFlags->f != 1)
                trueFlags->r = 1;
            break ;
        case 't':
            if (trueFlags->S != 1 && trueFlags->f != 1)
                trueFlags->t = 1;
            break ;
        case 'S':
            if (trueFlags->f != 1) {
                trueFlags->S = 1;
                trueFlags->t = 0;
            }
            break ;
        //5 group (c/u)
        case 'c':
            trueFlags->c = 1;
            trueFlags->u = 0;
            break ;
        case 'u':
            trueFlags->u = 1;
            trueFlags->c = 0;
            break ;
        //6 group (F/p)
        case 'F':
            trueFlags->F = 1;
            trueFlags->p = 0;
            break ;
        case 'p':
            trueFlags->p = 1;
            trueFlags->F = 0;
            break ;
        //7 group - single (R/G)
        case 'R':
            trueFlags->R = 1;
            break ;
        case 'G':
            trueFlags->G = 1;
            break ;
    }
}
