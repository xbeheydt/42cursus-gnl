/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:31:56 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:32:01 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <cunits42.h>

/* Mandatories */
cunits42_t	test_buffer_get_clear_buffer(void);
cunits42_t	test_line_realloc(void);
cunits42_t	test_get_line1(void);
cunits42_t	test_get_line2(void);
cunits42_t	test_get_line3(void);
cunits42_t	test_gnl_small_line_nonl(void);
cunits42_t	test_gnl_big_text_nl(void);
cunits42_t	test_gnl_big_text_alt_nl(void);
cunits42_t	test_gnl_one_nl(void);
cunits42_t	test_gnl_empty(void);
cunits42_t	test_gnl_fake_fd(void);

/* Bonus */
cunits42_t	test_new_lstbuf(void);
cunits42_t	test_get_lstbuf_create_one(void);
cunits42_t	test_get_lstbuf_create_tree(void);
cunits42_t	test_del_lstbuf(void);
cunits42_t	test_bonus_line_realloc(void);

#endif /* TEST_H */
