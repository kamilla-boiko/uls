#include "libmx.h"

void mx_printint(int n) {
    long int m = n;
    
    if (m < 0) {
        m = m * -1;
        mx_printchar('-');
    }
    if (m >= 0 && m <= 9) {
        mx_printchar(m + 48);
    }
    else {
        mx_printint(m / 10);
        mx_printchar((m % 10) + 48);
    } 
}
