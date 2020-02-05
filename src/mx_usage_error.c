#include "uls.h"

static void find_flag_l_or_t(t_flags *trueFlags, char *str);
static int get_index(char *str, char flag);
// static void print_struct_of_flags(t_flags *trueFlags);
static char *str_with_all_true_flags(char **argv, int argc);

t_list **mx_usage_error(int argc, char **argv) {
    int i = 1;
    int x = 0;
    char *str = NULL;
    t_flags trueFlags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    str = str_with_all_true_flags(argv, argc);
    find_flag_l_or_t(&trueFlags, str);
    for (; i < argc && x == 0; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            for (int k = 1; argv[i][k] != '\0'; k++)
                if (argv[i][0] == '-') {
                    if (get_index("afl1RAGh@eTCFmprtucS", argv[i][k]) == -1) {
                        write(2, "uls: illegal option -- ", 23);
                        write(2, &argv[i][k], 1);
                        write(2, "\nusage: uls [-laf] [file ...]\n", 30);
                        exit(0);
                    }
                    else
                        mx_select_flags(&trueFlags, argv[i][k]);
                }
                
        }
        else 
            x = i;
    // print_struct_of_flags(&trueFlags);
    return mx_parsing(x, argc, argv, &trueFlags);
}

static int get_index(char *str, char flag) {
    int index = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == flag)
            index = i;
    }
    return index;
}

static char *str_with_all_true_flags(char **argv, int argc) {
    char *str = NULL;
    int size = 0;
    int j = 0;
    int i = 1;
    int k = 1;
    
    for (i = 1; i < argc; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            for (k = 1; argv[i][k] != '\0'; k++)
                if (argv[i][0] == '-')
                    size = size + mx_strlen(argv[i]) - 1;
    str = mx_strnew(size);
    for (i = 1; i < argc; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            for (k = 1; argv[i][k] != '\0'; k++)
                if (argv[i][0] == '-') {
                    str[j] = argv[i][k];
                    j++;
                }
    return str;
}

static void find_flag_l_or_t(t_flags *trueFlags, char *str) {
    if (get_index(str, 'l') > get_index(str, 'C') &&
        get_index(str, 'l') > get_index(str, '1') &&
        get_index(str, 'l') > get_index(str, 'm')) 
        trueFlags->l = 1;
    if ((get_index(str, 't') != -1 || get_index(str, 'l') != -1) &&
        get_index(str, 'u') != -1 && get_index(str, 'c') == -1)
        trueFlags->u = 1;
    if ((get_index(str, 't') != -1 || get_index(str, 'l') != -1) &&
        get_index(str, 'c') != -1 && get_index(str, 'u') == -1)
        trueFlags->c = 1;
    if ((get_index(str, 't') != -1 || get_index(str, 'l') != -1) &&
        get_index(str, 'c') != -1 && get_index(str, 'u') != -1) {
        if (trueFlags->c != 1)
            trueFlags->u = 1;
        if (trueFlags->u != 1)
            trueFlags->c = 1;
        }
}

// static void print_struct_of_flags(t_flags *trueFlags) {
//     printf("%s %d\n", "flag a -", trueFlags->a);
//     printf("%s %d\n", "flag f -", trueFlags->f);
//     printf("%s %d\n", "flag l -", trueFlags->l);
//     printf("%s %d\n", "flag 1 -", trueFlags->one);
//     printf("%s %d\n", "flag R -", trueFlags->R);
//     printf("%s %d\n", "flag A -", trueFlags->A);
//     printf("%s %d\n", "flag G -", trueFlags->G);
//     printf("%s %d\n", "flag h -", trueFlags->h);
//     printf("%s %d\n", "flag @ -", trueFlags->dog);
//     printf("%s %d\n", "flag e -", trueFlags->e);
//     printf("%s %d\n", "flag T -", trueFlags->T);
//     printf("%s %d\n", "flag C -", trueFlags->C);
//     printf("%s %d\n", "flag F -", trueFlags->F);
//     printf("%s %d\n", "flag m -", trueFlags->m);
//     printf("%s %d\n", "flag p -", trueFlags->p);
//     printf("%s %d\n", "flag r -", trueFlags->r);
//     printf("%s %d\n", "flag t -", trueFlags->t);
//     printf("%s %d\n", "flag u -", trueFlags->u);
//     printf("%s %d\n", "flag c -", trueFlags->c);
//     printf("%s %d\n", "flag S -", trueFlags->S);
// }
