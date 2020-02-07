NAME = uls

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror 

INC = uls.h

SRC = main.c \
parsing.c \
usage_error.c \
select_flags.c \
check_flags.c \

OBJ = main.o \
parsing.o \
usage_error.o \
select_flags.o \
check_flags.o \

all: install clean

install:
	@make install -sC libmx
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj

uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)

clean: 
	@make clean -sC libmx
	@rm -rf $(INC) $(SRC) ./obj

reinstall: uninstall install
