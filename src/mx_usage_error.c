#include "uls.h"

static bool search_flag(char *str, char flag);

t_list **mx_usage_error(int argc, char **argv) {
    int i = 1;
    int x = 0;
    //t_list trueFlags = NULL;

    for (; i < argc && x == 0; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            for (int k = 1; argv[i][k] != '\0'; k++)
                if (argv[i][0] == '-') 
                    if (search_flag("laf", argv[i][k]) == 0) {
                        write(2, "uls: illegal option -- ", 23);
                        write(2, &argv[i][k], 1);
                        write(2, "\nusage: uls [-laf] [file ...]\n", 30);
                        exit(0);
                    }
        }
        else 
            x = i;
    return mx_parsing(x, argc, argv);
}

static bool search_flag(char *str, char flag) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == flag)
            return true;
    }
    return false;
}
