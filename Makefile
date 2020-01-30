NAME = uls

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror 

INC = uls.h

SRC = main.c \
mx_parsing.c \
mx_usage_error.c \

OBJ = main.o \
mx_parsing.o \
mx_usage_error.c \

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
