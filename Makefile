NAME = uls

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror 

INC = uls.h

SRC = main.c \
parsing.c \
usage_error.c \
select_flags.c \
check_flags.c \
select_flags_fifth.c \
select_flags_first.c \
select_flags_fourth.c \
select_flags_second.c \
select_flags_sixth.c \
select_flags_third.c \

OBJ = main.o \
parsing.o \
usage_error.o \
select_flags.o \
check_flags.o \
select_flags_fifth.o \
select_flags_first.o \
select_flags_fourth.o \
select_flags_second.o \
select_flags_sixth.o \
select_flags_third.o \

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
