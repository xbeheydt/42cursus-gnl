LIBTEST			= cunits42
TESTMANDATORY	= tests/test_buffer_handlers.c \
				  tests/test_get_line.c \
				  tests/test_get_next_line.c \
				  tests/test_line_realloc.c \
				  tests/test_mandatories.c

TESTBONUS		= tests/test_bonus_lstbuf_handlers.c \
				  tests/test_bonus_utils.c \
				  tests/test_bonus.c

HEADERS			= src/get_next_line.h
SRCS			= src/get_next_line.c \
				  src/get_next_line_utils.c

HEADERS_BONUS	= src/get_next_line_bonus.h
SRCS_BONUS		= src/get_next_line_bonus.c \
				  src/get_next_line_utils_bonus.c

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g3
IFLAGS			= -Isrc/ -Ideps/${LIBTEST}/include -Itests/ -Ideps/libft
LFLAGS			= -Ldeps/${LIBTEST}/lib -Ldeps/libft

RM				= rm -rf
NORM			= ${HOME}/.local/bin/norminette

all: mandatory bonus

libtest:
	$(MAKE) -C deps/${LIBTEST} all

mandatory: libtest
	$(CC) ${CFLAGS} -DBUFFER_SIZE=${BUFFER_SIZE} ${IFLAGS} ${LFLAGS} ${SRCS} ${TESTMANDATORY} -o mandatory.out -l${LIBTEST} -lft

run-mandatory: mandatory
	@echo
	@echo "Tests GNL Mandatories"
	@./mandatory.out

bonus: libtest
	$(CC) ${CFLAGS} -DBUFFER_SIZE=${BUFFER_SIZE} ${IFLAGS} ${LFLAGS} ${SRCS_BONUS} ${TESTBONUS} -o bonus.out -l${LIBTEST} -lft

run-bonus: bonus
	@echo
	@echo "Tests GNL Bonus"
	@./bonus.out

lint:
	$(NORM) ${HEADERS} ${SRCS}

clean:
	$(MAKE) -C deps/${LIBTEST} clean

fclean: clean
	$(MAKE) -C deps/${LIBTEST} fclean
	$(RM) mandatory.out
	$(RM) bonus.out

re: fclean all
	

.PHONY: clean fclean run-test re all test-bufsize
