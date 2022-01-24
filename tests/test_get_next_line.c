/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:33:48 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:33:50 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define _GNU_SOURCE

#include <cunits42.h>
#include <get_next_line.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static cunits42_t	test_get_next_line(const char *path)
{
	int		fd;
	FILE	*f;
	char	*line1;
	char	*line2;
	size_t	len;
	int		rread;

	line1 = NULL;
	line2 = NULL;
	len = 0;
	fd = open(path, O_RDONLY);
	f = fopen(path, "r");
	while (1)
	{
		line1 = get_next_line(fd);
		if (fd != -1)
			rread = getline(&line2, &len, f);
		else
			rread = -1;
		if (rread == -1)
		{
			free(line1);
			line2 = NULL;
			UNIT_TEST(line1, == , line2);
			break ;
		}
		else
		{
			UNIT_TEST(strcmp(line1, line2), == , 0);
			free(line1);
		}
	}
	close(fd);
	if (fd != -1)
		fclose(f);
	return (CUNITS42_OK);
}

cunits42_t	test_gnl_small_line_nonl(void)
{
	return (
		test_get_next_line("/tmp/gnl/tests/data/test1.txt")
		);
}

cunits42_t	test_gnl_big_text_nl(void)
{
	return (
		test_get_next_line("/tmp/gnl/tests/data/test2.txt")
		);
}

cunits42_t	test_gnl_big_text_alt_nl(void)
{
	return (
		test_get_next_line("/tmp/gnl/tests/data/test2_alt.txt")
		);
}

cunits42_t	test_gnl_one_nl(void)
{
	return (
		test_get_next_line("/tmp/gnl/tests/data/one-nl.txt")
		);
}

cunits42_t	test_gnl_empty(void)
{
	return (
		test_get_next_line("/tmp/gnl/tests/data/empty.txt")
		);
}

cunits42_t	test_gnl_fake_fd(void)
{
	return (
		test_get_next_line("/foo/bar")
		);
}
