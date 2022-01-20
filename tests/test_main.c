#include "test.h"

#include <stdio.h>
#include <stdlib.h>

#include <cunits42.h>
#include <get_next_line.h>


static cunits42_test_t	tests[] = {
	{ TEST_FCN(test_ft_realloc), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_ft_memmove), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_ft_memcat), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_getbuffer), NULL, clear_buffer, CUNITS42_RUN },
	{ TEST_FCN(test_buffer_is_static), setup_buffer, clear_buffer, CUNITS42_RUN },
	{ TEST_FCN(test_clearbuffer), setup_buffer, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_readbuffer), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_get_line1), setup_get_line1, clear_get_line_buffer, CUNITS42_RUN },
	{ TEST_FCN(test_get_line2), NULL, clear_get_line_buffer, CUNITS42_RUN },
	CUNITS42_TEST_STOP
};

int	main(int argc, const char *argv[])
{
	return (main_test(tests, argc, argv));
}
