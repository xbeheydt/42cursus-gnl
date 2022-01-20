LIBTEST			= cunits42
TESTSRC			= tests/test_*.c
HEADERS			= src/get_next_line.h
SRCS			= src/get_next_line.c \
				  src/get_next_line_utils.c

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g3
IFLAGS			= -Isrc/ -Ideps/${LIBTEST}/include -Itests/ -Ideps/libft
LFLAGS			= -Ldeps/${LIBTEST}/lib -Ldeps/libft

RM				= rm -rf
NORM			= ${HOME}/.local/bin/norminette

all: lint
	$(MAKE) -C deps/${LIBTEST} all
	$(CC) ${CFLAGS} -DBUFFER_SIZE=1024 -DDATA_PATH="${DATA_PATH}" ${IFLAGS} ${LFLAGS} ${SRCS} ${TESTSRC} -o a.out -l${LIBTEST} -lft

gnl.out:
	$(CC) ${CFLAGS} -Isrc/ ${SRCS} -o gnl.out

lint:
	$(NORM) ${HEADERS} ${SRCS}

clean:
	$(MAKE) -C deps/${LIBTEST} clean

fclean: clean
	$(MAKE) -C deps/${LIBTEST} fclean
	$(RM) gnl.out
	$(RM) a.out

re: fclean all
	
run-test: all
	@./a.out

.PHONY: clean fclean run-test re all
