/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:32:21 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:32:26 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#include <cunits42.h>
#include <get_next_line_bonus.h>

static cunits42_test_t	tests[] = {
	{ TEST_FCN(test_new_lstbuf), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_get_lstbuf_create_one), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_get_lstbuf_create_tree), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_del_lstbuf), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_bonus_line_realloc), NULL, NULL, CUNITS42_RUN },
	CUNITS42_TEST_STOP
};

int	main(int argc, const char *argv[])
{
	return (main_test(tests, argc, argv));
}
