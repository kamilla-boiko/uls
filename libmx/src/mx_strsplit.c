#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    int size_arr = mx_count_words(s, c);
    char **arr = malloc((size_arr + 1) * sizeof(char *));

    if (s == NULL)
        return NULL;
    for (int i = 0; i < size_arr; i++) {
        while (*s == c)
            s++;
        arr[i] = mx_strnew(mx_strlen_my(s, c));
        for (int j = 0; *s != c; j++) {
            arr[i][j] = *s;
            s++;
        }
    }
    arr[size_arr] = NULL;
    return arr;
}
