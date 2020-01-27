#include "uls.h"

static bool search_flag(char *str, char flag);
static void errors(int argc, char **argv);

void mx_parsing(int argc, char **argv) {
    errors(argc, argv);
}

static void errors(int argc, char **argv) {
    char *flags = mx_strnew(3);
    int fd = 0;
    // DIR *dir = NULL;

    flags = "laf";
    for (int i = 1; i < argc; i++) {
        for (int k = 1; argv[i][k] != '\0'; k++) {
            if (argv[i][0] == '-') {
                if (search_flag(flags, argv[i][k]) == 0) {
                    write(2, "uls: illegal option -- ", 23);
                    write(2, &argv[i][k], 1);
                    write(2, "\nusage: uls [-l] [file ...]\n", 28);
                    exit(0);
                }
            }
        }
        if (argv[i][0] != '-') {
            fd = open(argv[i], O_RDONLY);
            // dir = opendir(argv[i]);
            // if (dir || fd) {
            if (fd) {
                
            }
            // else if (fd < 0 || !dir) {
            else if (fd < 0) {
                write(2, "uls: ", 5);
                write(2, argv[i], mx_strlen(argv[i]));
                write(2, ": No such file or directory\n", 28);
                exit(0);
            }
            // closedir(dir);
            close(fd);
        }
    }
}

static bool search_flag(char *str, char flag) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == flag)
            return true;
    }
    return false;
}
