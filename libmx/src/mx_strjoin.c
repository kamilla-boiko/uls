#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *str1 = NULL;
    char *str2 = NULL;
    char *s = NULL;

    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL)
        return mx_strdup(s2);
    if (s2 == NULL)
        return mx_strdup(s1);
    else {
        str1 = mx_strdup(s1);
        str2 = mx_strdup(s2);
        s = mx_strcat(str1, str2);
        mx_strdel(&str2);
        return s;
    }
}
