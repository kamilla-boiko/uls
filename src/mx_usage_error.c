#include "uls.h"

static bool search_flag(char *str, char flag);

t_list **mx_usage_error(int argc, char **argv) {
    int i = 1; 
    char *lsFlags = mx_strnew(3);

    lsFlags = "laf";
    for (; argv[i][0] == '-'; i++) {
        for (int k = 1; argv[i][k] != '\0'; k++) {
            if (argv[i][0] == '-') {
                if (search_flag(lsFlags, argv[i][k]) == 0) {
                    write(2, "uls: illegal option -- ", 23);
                    write(2, &argv[i][k], 1);
                    write(2, "\nusage: uls [-l] [file ...]\n", 28);
                    exit(0);
                }
            }
        }
    }
    return mx_parsing(i, argc, argv);
}

static bool search_flag(char *str, char flag) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == flag)
            return true;
    }
    return false;
}