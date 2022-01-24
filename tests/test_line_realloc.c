#include "test.h"

#include <cunits42.h>
#include <get_next_line.h>
#include <libft.h>
#include <string.h>
#include <stdlib.h>

cunits42_t	test_line_realloc(void)
{
    t_buffer	*buf;

	buf = NULL;
	get_buffer(&buf);
    line_realloc(&buf, 6);
    memcpy(buf->line, "Hello", 5);
	buf->llen = 5;
    UNIT_TEST(memcmp(buf->line, "Hello", buf->llen), == , 0);

    line_realloc(&buf, 12);
    memcpy(buf->line + 5, " World", 6);
	buf->llen = 11;
    UNIT_TEST(memcmp(buf->line, "Hello World", buf->llen), == , 0);
    
    line_realloc(&buf, 22);
    memcpy(buf->line + 11, "IpsumLorem", 10);
	buf->llen = 21;
    UNIT_TEST(ft_memcmp(buf->line, "Hello WorldIpsumLorem", buf->llen), == , 0);

	clear_buffer(&buf);
    return (CUNITS42_OK);
}
