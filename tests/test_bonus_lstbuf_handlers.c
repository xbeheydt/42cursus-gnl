#include "test.h"

#include <cunits42.h>
#include <get_next_line_bonus.h>
#include <stdlib.h>

cunits42_t	test_new_lstbuf(void)
{
	t_lstbuf	*lstbuf;

	lstbuf = NULL;
	lstbuf = new_lstbuf(42);
	if (lstbuf == NULL)
		return (CUNITS42_KO);
	
	UNIT_TEST(lstbuf->fd, == , 42);
	UNIT_TEST(lstbuf->fpos, == , 0);
	UNIT_TEST(lstbuf->flen, == , 0);
	UNIT_TEST(lstbuf->line, == , NULL);
	UNIT_TEST(lstbuf->flen, == , 0);
	UNIT_TEST(lstbuf->next, == , NULL);
	free(lstbuf);
	lstbuf = NULL;
	return (CUNITS42_OK);
}

cunits42_t	test_get_lstbuf_create_one(void)
{
	t_lstbuf	*lstbuf;

	lstbuf = NULL;
	UNIT_TEST(get_lstbuf(&lstbuf, 1), ==, lstbuf);
	UNIT_TEST(lstbuf->fd, == , 1);
	UNIT_TEST(lstbuf->fpos, == , 0);
	UNIT_TEST(lstbuf->flen, == , 0);
	UNIT_TEST(lstbuf->line, == , NULL);
	UNIT_TEST(lstbuf->flen, == , 0);
	UNIT_TEST(lstbuf->next, == , NULL);
	free(lstbuf);
	lstbuf = NULL;
	return (CUNITS42_OK);
}

cunits42_t	test_get_lstbuf_create_tree(void)
{
	t_lstbuf	*lst;
	t_lstbuf	*cpy;

	lst = NULL;
	cpy = NULL;
	UNIT_TEST(get_lstbuf(&lst, 1), == , lst);
	cpy = lst;
	cpy = get_lstbuf(&lst, 2);
	UNIT_TEST(cpy, != , lst);
	UNIT_TEST(cpy, == , lst->next);
	cpy = get_lstbuf(&lst, 3);
	UNIT_TEST(cpy, != , lst);
	UNIT_TEST(cpy, != , lst->next);
	UNIT_TEST(cpy, == , lst->next->next);

	cpy = get_lstbuf(&lst, 1);
	UNIT_TEST(cpy->fd, == , 1);
	cpy = get_lstbuf(&lst, 2);
	UNIT_TEST(cpy->fd, == , 2);

	free(lst->next->next);
	lst->next->next = NULL;
	free(lst->next);
	lst->next = NULL;
	free(lst);
	lst = NULL;
	cpy = NULL;
	return (CUNITS42_OK);
}

cunits42_t	test_del_lstbuf(void)
{
	t_lstbuf	*lstbuf;
	t_lstbuf	*cur;
	int			i;
	int			fds[] = {4, 6, 8, 10};

	lstbuf = NULL;
	i = 0;
	while (i < 4)
	{
		cur = get_lstbuf(&lstbuf, fds[i]);
		cur->line = malloc(10 * sizeof(char));
		++i;
	}

	UNIT_TEST(del_lstbuf(&lstbuf, get_lstbuf(&lstbuf, 6)), == , NULL);
	UNIT_TEST(lstbuf->next->fd, == , 8);
	UNIT_TEST(del_lstbuf(&lstbuf, get_lstbuf(&lstbuf, 8)), == , NULL);
	UNIT_TEST(lstbuf->fd, == , 4);
	UNIT_TEST(lstbuf->next->fd, == , 10);
	UNIT_TEST(del_lstbuf(&lstbuf, get_lstbuf(&lstbuf, 10)), == , NULL);
	UNIT_TEST(del_lstbuf(&lstbuf, get_lstbuf(&lstbuf, 4)), == , NULL);
	UNIT_TEST(lstbuf, == , NULL);

	return(CUNITS42_OK);
}
