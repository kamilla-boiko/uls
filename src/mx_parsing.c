#include "uls.h"

t_list **mx_parsing(int i, int argc, char **argv) {
    t_list **Parser = malloc(5 * sizeof(t_list *));
    DIR *dir = NULL;
    int fd = 0;

    for (int h = 0; h < 5; h++)
        Parser[h] = NULL;
    for (; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        dir = opendir(argv[i]);
        if (!dir) {
            if (errno == ENOENT) {
                if (Parser[1] == NULL)
                    Parser[1] = mx_create_node(argv[i]);
                else
                    mx_push_back(&Parser[1], argv[i]);
            }
            if (fd > 0) {
                if (Parser[2] == NULL)
                    Parser[2] = mx_create_node(argv[i]);
                else
                    mx_push_back(&Parser[2], argv[i]);
            }
            if (errno == EACCES) {
                if (Parser[3] == NULL)
                    Parser[3] = mx_create_node(argv[i]);
                else
                    mx_push_back(&Parser[3], argv[i]);
            }
        }
        if (dir) {
            if (Parser[4] == NULL)
                Parser[4] = mx_create_node(argv[i]);
            else
                mx_push_back(&Parser[4], argv[i]);
        }
        //closedir(dir);
    }
    return Parser;
}
