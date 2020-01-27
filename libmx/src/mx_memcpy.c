#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    unsigned int i = 0;
    
    while(i != n) {
        *d++ = *s++;
        i++;
    }
    return dst;
}
