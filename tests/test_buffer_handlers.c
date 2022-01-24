/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_buffer_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:33:40 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:33:43 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#include <cunits42.h>
#include <get_next_line.h>
#include <stdlib.h>

cunits42_t	test_buffer_get_clear_buffer(void)
{
	t_buffer	*buf;

	buf = NULL;
	get_buffer(&buf);
	UNIT_TEST(buf->fpos, == , 0);
	UNIT_TEST(buf->flen, == , 0);
	UNIT_TEST(buf->line, == , NULL);
	UNIT_TEST(buf->llen, == , 0);

	buf->line = malloc(4096);
	if (buf->line)
	{
		clear_buffer(&buf);
		UNIT_TEST(buf, == , NULL);
	}
	return (CUNITS42_OK);
}
