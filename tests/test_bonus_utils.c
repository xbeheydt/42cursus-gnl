/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:34:15 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:34:25 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#include <cunits42.h>
#include <get_next_line_bonus.h>
#include <string.h>

cunits42_t	test_bonus_line_realloc(void)
{
	t_lstbuf	*buf;
	const char	*s = "Hello World";

	buf = NULL;
	buf = new_lstbuf(5);
	UNIT_TEST(line_realloc(&buf, 6), == , buf->line);
	strncpy(buf->line, s, 5);
	buf->line[5] = 0;
	buf->llen = 5;
	UNIT_TEST(strcmp(buf->line, "Hello"), == , 0);
	UNIT_TEST(line_realloc(&buf, 12), == , buf->line);
	strncpy(buf->line, s, 12);
	buf->line[11] = 0;
	UNIT_TEST(strcmp(buf->line, "Hello World"), == , 0);
	del_lstbuf(&buf, buf);
	return (CUNITS42_OK);
}
