#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned int i = 0;
    const unsigned char *str1 = s1;
    const unsigned char *str2 = s2;

    while (*str1 != '\0' && i < n) {
        if (*str1 != *str2)
           return *str1 - *str2;
        i++;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
