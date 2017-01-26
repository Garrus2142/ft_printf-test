/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:29:46 by thugo             #+#    #+#             */
/*   Updated: 2017/01/26 20:28:57 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "capture_stdout.h"

static int	h_ret1, h_ret2;
static char	*h_buffer1, *h_buffer2;
static size_t	h_size1, h_size2;
static int		h_diffprint, h_diffreturn;
static int		num_fail = 0;
static int		num_ok = 0;

# define ADD_PRINTF_TEST(...) \
	h_diffprint = 0; \
	h_diffreturn = 0; \
	capture_start(); \
	h_ret1 = ft_printf(__VA_ARGS__); \
	h_buffer1 = capture_getbuffer(&h_size1); \
	h_ret2 = printf(__VA_ARGS__); \
	h_buffer2 = capture_getbuffer(&h_size2); \
	capture_end(); \
	if (h_size1 != h_size2 || memcmp(h_buffer1, h_buffer2, h_size1) != 0) \
		h_diffprint = 1; \
	if (h_ret1 != h_ret2) \
		h_diffreturn = 1; \
	num_fail += h_diffprint | h_diffreturn; \
	num_ok += !h_diffprint | !h_diffreturn; \
	printf("[%s]\t%s\n", (h_diffprint + h_diffreturn) ? "\033[31mFAIL\033[0m" : "\033[32mOK\033[0m", #__VA_ARGS__); \
	if (h_diffprint + h_diffreturn > 0) \
	{ \
		printf("-------------- \033[31mFAIL RESULT\033[0m ---------------\n"); \
		printf("\033[34mft_printf:\033[0m"); \
		write(STDOUT_FILENO, h_buffer1, h_size1); \
		printf("\033[34m$\n   printf:\033[0m"); \
		write(STDOUT_FILENO, h_buffer2, h_size2); \
		printf("\033[34m$\nreturn ft_printf:\033[0m %d\n", h_ret1); \
		printf("\033[34mreturn printf:\033[0m %d\n", h_ret2); \
		printf("------------------------------------------\n"); \
	}

# define PRINT_TESTS_RESULT(NAME) \
	printf("%s=============== Result %s ================\033[0m\n", num_fail > 0 ? "\033[31m" : "\033[32m", NAME); \
	printf("%d test(s) ok. (%d / %d)\n", num_ok,  num_ok, num_ok + num_fail); \
	printf("%d test(s) fail.\n\n", num_fail); \
	num_ok = 0; \
	num_fail = 0;
	
int	ft_printf(const char *format, ...);

#endif
