/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:29:13 by thugo             #+#    #+#             */
/*   Updated: 2017/01/25 22:32:55 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf_test.h"

int	main(int argc, char **argv)
{
	printf("\033[34m=============== PRINTF CHECKER ================\033[0m\n");
	printf("Legend:\n\tLine 1: Test values\n\tLine 2: Your printf\n\tLine 3: Unix printf\n\tLine 4: Return values\n");
	printf("\033[34m===============================================\033[0m\n\n");
	
	if (argc <= 1)
	{
		normal_tests();
		undefined_tests();
	}
	else if (argc >= 2)
	{
		if (strcmp(argv[1], "1") == 0)
			normal_tests();
		else if (strcmp(argv[1], "2") == 0)
			undefined_tests();
		else
			printf("Usage: %s [1 | 2] (1: normal tests, 2: undefined tests)\n", argv[0]);
	}
	return (0);
}
