#include "uls.h"

static bool search_flag(char *str, char flag);
static void find_flag_l(t_flags *trueFlags, char **argv, int argc);

t_list **mx_usage_error(int argc, char **argv) {
    int i = 1;
    int x = 0;
    t_flags trueFlags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    find_flag_l(&trueFlags, argv, argc);
    for (; i < argc && x == 0; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            for (int k = 1; argv[i][k] != '\0'; k++)
                if (argv[i][0] == '-') {
                    if (search_flag("afl1RAGh@eTCFmprtucS", argv[i][k]) == 0) {
                        write(2, "uls: illegal option -- ", 23);
                        write(2, &argv[i][k], 1);
                        write(2, "\nusage: uls [-laf] [file ...]\n", 30);
                        exit(0);
                    }
                    else
                        mx_select_flags(&trueFlags, argv[i][k]);
                }
                printf("%d\n", trueFlags.h);
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

static void find_flag_l(t_flags *trueFlags, char **argv, int argc) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            for (int k = 1; argv[i][k] != '\0'; k++) {
                if (argv[i][0] == '-') {
                    if (mx_get_char_index(argv[i], 'l') > mx_get_char_index(argv[i], 'C') &&
                        mx_get_char_index(argv[i], 'l') > mx_get_char_index(argv[i], '1') &&
                        mx_get_char_index(argv[i], 'l') > mx_get_char_index(argv[i], 'm')) 
                        trueFlags->l = 1;
                }
            }
        }
    }
}
