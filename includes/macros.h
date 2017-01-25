/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:29:46 by thugo             #+#    #+#             */
/*   Updated: 2017/01/25 22:37:27 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include <stdio.h>

static int	ret1, ret2;

# define ADD_PRINTF_TEST(FORMAT, ...) \
	printf("\033[33m++++++++++++++++ \033[0mft_printf(\"\033[33m%s\033[0m\", %s)\033[33m ++++++++++++++++\033[0m\n", FORMAT, #__VA_ARGS__); \
	ret1 = ft_printf(FORMAT, __VA_ARGS__); \
	printf("$\n"); \
	ret2 = printf(FORMAT, __VA_ARGS__); \
	printf("$\n"); \
	if (ret1 != ret2) \
		printf("\033[31m"); \
	else \
		printf("\033[32m"); \
	printf("--------------- ft_printf return: %d printf return: %d ---------------\033[0m\n\n", ret1, ret2);

int	ft_printf(const char *format, ...);

#endif
