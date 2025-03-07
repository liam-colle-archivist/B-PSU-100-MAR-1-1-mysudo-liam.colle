##
## EPITECH PROJECT, 2024
## main
## File description:
## Makefile v1
##

NAME = my_sudo

DEBUG = my_sudo_dbg

SRC = $(wildcard *.c) $(shell find ./src/. -type f -name '*.c')

TNAME = unit_tests

TOBJ = $(filter-out main.c,$(wildcard *.c)) \
	$(shell find ./src/. -type f -name '*.c')

TFILE = $(shell find ./tests/ -type f -name '*.c')

OBJ = $(SRC:.c=.o)

LIBS = -lcrypt -L. -lmy -largparser -lstatutils -lusage

LIBDIRS := $(wildcard ./lib/*/)

DBGFLAGS = -Wall -Wextra -g3

CFLAGS = -Wall -Wextra -I./include/ $(LIBS)

TCFLAGS = -lcriterion

all: libs $(NAME)

dbg: dbg_libs $(DEBUG)

admin:
	cp $(NAME) $(NAME)-noflags
	sudo chown root:root $(NAME)
	sudo chmod +s $(NAME)

admin_dbg:
	cp $(DEBUG) $(DEBUG)-noflags
	sudo chown root:root $(DEBUG)
	sudo chmod +s $(DEBUG)

$(NAME): $(OBJ)
	@$(CC) $(SRC) -o $(NAME) $(CFLAGS)

$(DEBUG): $(OBJ)
	@$(CC) $(SRC) -o $(DEBUG) $(DBGFLAGS) $(CFLAGS)

libs: $(LIBDIRS)
	@for fld in $^ ; do $(MAKE) -C $$fld --no-print-directory ; done

dbg_libs: $(LIBDIRS)
	@for fld in $^ ; do $(MAKE) -C $$fld CFLAGS='$(DBGFLAGS)' \
		--no-print-directory ; done

clean:
	@for fld in $(LIBDIRS) ; do $(MAKE) clean -C $$fld \
		--no-print-directory ; done
	@$(RM) $(OBJ)
	@$(RM) unit_tests *.gc*

fclean: clean
	@for fld in $(LIBDIRS) ; do $(MAKE) fclean -C $$fld \
		--no-print-directory ; done
	@$(RM) $(NAME)
	@$(RM) $(NAME)-noflags
	@$(RM) $(DEBUG)
	@$(RM) $(DEBUG)-noflags

re: fclean all

dbg_re: fclean dbg

style: fclean
	@../coding-style-checker/coding-style.sh ./
	@cat coding-style-reports.log
	@$(RM) -f coding-style-reports.log

tests_run: unit_tests
	@./unit_tests

unit_tests: re
	@$(CC) $(TOBJ) $(TFILE) -o $(TNAME) $(TCFLAGS) $(CFLAGS)
