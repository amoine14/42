/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_pointer_bonus.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 01:15:10 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:15:11 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include <stdio.h>

static void	test_pointer(const char *fmt, void *ptr)
{
	const char		*cursor;
	t_printf_format	format;
	int				expected;
	int				actual;

	cursor = fmt + 1;
	if (!ft_parse_format(&cursor, &format))
		return ;
	printf("\nFormat : [%s]\n", fmt);
	printf("printf    : [");
	fflush(stdout);
	expected = printf(fmt, ptr);
	printf("] (%d)\n", expected);
	printf("ft_format : [");
	fflush(stdout);
	actual = ft_format_pointer(ptr, &format);
	printf("] (%d)\n", actual);
}

int	main(void)
{
	int	n;

	n = 42;
	printf("========== POINTERS ==========\n");
	test_pointer("%p", &n);
	test_pointer("%12p", &n);
	test_pointer("%-20p", &n);
	test_pointer("%020p", &n);
	test_pointer("%.20p", &n);
	test_pointer("%25.20p", &n);
	printf("\n========== NULL POINTERS ==========\n");
	test_pointer("%p", NULL);
	test_pointer("%10p", NULL);
	test_pointer("%-10p", NULL);
	test_pointer("%010p", NULL);
	return (0);
}
