/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mandatories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:34:03 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:34:09 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#include <cunits42.h>
#include <get_next_line.h>

static cunits42_test_t	tests[] = {
	{ TEST_FCN(test_buffer_get_clear_buffer), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_line_realloc), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_get_line1), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_get_line2), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_get_line3), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_gnl_small_line_nonl), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_gnl_big_text_nl), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_gnl_big_text_alt_nl), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_gnl_one_nl), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_gnl_empty), NULL, NULL, CUNITS42_RUN },
	{ TEST_FCN(test_gnl_fake_fd), NULL, NULL, CUNITS42_RUN },
	CUNITS42_TEST_STOP
};

int	main(int argc, const char *argv[])
{
	return (main_test(tests, argc, argv));
}
