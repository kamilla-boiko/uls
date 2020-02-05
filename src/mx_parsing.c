#include "uls.h"

static void add_to_Parser(char *argv, t_list **Parser, int k);
static void print_Parser(t_list **Parser);
static void distributor(char *argv, t_list **Parser);
static void flags_to_Parser(t_list **Parser, t_flags *trueFlags);

t_list **mx_parsing(int i, int argc, char **argv, t_flags *trueFlags) {
    t_list **Parser = malloc(5 * sizeof(t_list *));
    
    for (int h = 0; h < 5; h++)
        Parser[h] = NULL;
    flags_to_Parser(Parser, trueFlags);
    if (i == 0)
        Parser[4] = mx_create_node(".");
    else {
        for (; i < argc; i++) {
            distributor(argv[i], Parser);
        }
    }
    print_Parser(Parser);
    return Parser;
}

static void add_to_Parser(char *argv, t_list **Parser, int k) {
    if (Parser[k] == NULL)
        Parser[k] = mx_create_node(argv);
    else
        mx_push_back(&Parser[k], argv);
}

static void distributor(char *argv, t_list **Parser) {
    DIR *dir = NULL;
    int fd = 0;

    fd = open(argv, O_RDONLY);
    dir = opendir(argv);
    if (!dir) {
        if (errno == ENOENT)
            add_to_Parser(argv, Parser, 1);
        if (fd > 0)
            add_to_Parser(argv, Parser, 2);
        if (errno == EACCES)
            add_to_Parser(argv, Parser, 3);
    }
    else
        add_to_Parser(argv, Parser, 4);
}

static void flags_to_Parser(t_list **Parser, t_flags *trueFlags) {
    Parser[0] = mx_create_node("C");
    printf("%s\n", Parser[0]->data);
    if (trueFlags->R == 1)
        mx_push_back(&Parser[0], "R");
    if (trueFlags->a == 1)
        mx_push_back(&Parser[0], "a");
    if (trueFlags->A == 1)
        mx_push_back(&Parser[0], "A");
    if (trueFlags->l == 1)
        mx_push_back(&Parser[0], "l");
    if (trueFlags->C == 0)
        mx_pop_front(&Parser[0]);
    if (trueFlags->one == 1)
        mx_push_back(&Parser[0], "1");
    if (trueFlags->m == 1)
        mx_push_back(&Parser[0], "m");
    if (trueFlags->h == 1)
        mx_push_back(&Parser[0], "h");
    if (trueFlags->dog == 1)
        mx_push_back(&Parser[0], "@");
    if (trueFlags->e == 1)
        mx_push_back(&Parser[0], "e");
    if (trueFlags->T == 1)
        mx_push_back(&Parser[0], "T");
    if (trueFlags->f == 1)
        mx_push_back(&Parser[0], "f");
    if (trueFlags->r == 1)
        mx_push_back(&Parser[0], "r");
    if (trueFlags->S == 1)
        mx_push_back(&Parser[0], "S");
    if (trueFlags->t == 1)
        mx_push_back(&Parser[0], "t");
    if (trueFlags->u == 1)
        mx_push_back(&Parser[0], "u");
    if (trueFlags->c == 1)
        mx_push_back(&Parser[0], "c");
    if (trueFlags->p == 1)
        mx_push_back(&Parser[0], "p");
    if (trueFlags->F == 1)
        mx_push_back(&Parser[0], "F");
    if (trueFlags->G == 1)
        mx_push_back(&Parser[0], "G");
}

static void print_Parser(t_list **Parser) {
    for (int i = 0; i < 5; i++) {
        mx_printstr("Potok ");
        mx_printint(i);
        mx_printchar('\n');
        while (Parser[i] != NULL) {
            mx_printstr(Parser[i]->data);
            mx_printchar(' ');
            Parser[i] = Parser[i]->next;
        }
        mx_printchar('\n');
    }
}
