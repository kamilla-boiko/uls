#include "uls.h"

void mx_select_flags(t_flags *trueFlags, char flag) {
    switch(flag) {
    	//1 group (a/A)
        case 'a':
            trueFlags->a = 1;
            trueFlags->A = 0;
            break;
        case 'A':
            trueFlags->A = 1;
            break;
        //2 group (1/C/l/m)
        case 'l':
            trueFlags->l = 1;
            trueFlags->C = 0;
            trueFlags->one = 0;
            trueFlags->m = 0;
            break;
        case '1':
            trueFlags->one = 1;
            trueFlags->C = 0;
            trueFlags->l = 0;
            trueFlags->m = 0;
            break;
        case 'm':
            trueFlags->m = 1;
            trueFlags->C = 0;
            trueFlags->one = 0;
            trueFlags->l = 0;
            break;
        case 'C':
            if (trueFlags->m != 1) {
                trueFlags->C = 1;
                trueFlags->l = 0;
                trueFlags->one = 0;
                break;
            }
        //3 group (h/@/e/T)
        case 'h':
            if (trueFlags->l == 1) {
                trueFlags->h = 1;
                break;
            }
        case '@':
            if (trueFlags->l == 1) {
                trueFlags->dog = 1;
                break;
            }
        case 'e':
            if (trueFlags->l == 1) {
                trueFlags->e = 1;
                break;
            }
        case 'T':
            if (trueFlags->l == 1) {
                trueFlags->T = 1;
                break;
            }
    }
}
