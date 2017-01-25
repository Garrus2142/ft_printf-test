/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 22:17:08 by thugo             #+#    #+#             */
/*   Updated: 2017/01/25 23:00:34 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"

void	normal_tests(void)
{
	ADD_PRINTF_TEST("%+.0d", 0)
	ADD_PRINTF_TEST("%.3s", NULL)
	ADD_PRINTF_TEST("%#.5x", 0)
	ADD_PRINTF_TEST("%#.5x", 32)
	ADD_PRINTF_TEST("%.3o", 1)
	ADD_PRINTF_TEST("%#0.3o", 0)
	ADD_PRINTF_TEST("%#.3o", 1)
	ADD_PRINTF_TEST("%#0.3o", 1)
	ADD_PRINTF_TEST("%+05d", 55)
	ADD_PRINTF_TEST("%.5d", -42)
	ADD_PRINTF_TEST("%hhu", -42)
	ADD_PRINTF_TEST("%+.5d", 55)
	ADD_PRINTF_TEST("%+ 04d", 40)
	ADD_PRINTF_TEST("%#04x", 0)
	ADD_PRINTF_TEST("%.4s", "123456789")
	ADD_PRINTF_TEST("%.42s", "123456789")
	ADD_PRINTF_TEST("%s", "");
	ADD_PRINTF_TEST("%c", 0);
	ADD_PRINTF_TEST("%#09.0X", 482)
	ADD_PRINTF_TEST("%#09.0o", 482)
}
