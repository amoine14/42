/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_integer_bonus.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 23:59:26 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:05:17 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

static void	test_integer(const char *fmt, int n)
{
	const char		*cursor;
	t_printf_format	format;
	int				expected;
	int				actual;

	cursor = fmt + 1;
	if (!ft_parse_format(&cursor, &format))
		return ;
	printf("\nFormat : [%s] | n = %d\n", fmt, n);
	printf("printf    : [");
	fflush(stdout);
	expected = printf(fmt, n);
	printf("] (%d)\n", expected);
	printf("ft_format : [");
	fflush(stdout);
	actual = ft_format_integer(n, &format);
	printf("] (%d)\n", actual);
}

int	main(void)
{
	test_integer("%d", 42);
	test_integer("%8d", 42);
	test_integer("%-8d", 42);
	test_integer("%08d", 42);
	test_integer("%08d", -42);
	test_integer("%-08d", 42);
	test_integer("%05d", 0);
	test_integer("%012d", INT_MIN);
	printf("\n========== PRECISION TESTS ==========\n");
	test_integer("%.5d", 42);
	test_integer("%.5d", -42);
	test_integer("%.2d", 12345);
	test_integer("%.12d", INT_MIN);
	printf("\n========== WIDTH + PRECISION ==========\n");
	test_integer("%8.5d", 42);
	test_integer("%8.5d", -42);
	test_integer("%-8.5d", 42);
	test_integer("%08.3d", 42);
	test_integer("%10.3d", -42);
	printf("\n========== ZERO EDGE CASES ==========\n");
	test_integer("%.0d", 0);
	test_integer("%5.0d", 0);
	test_integer("%-5.0d", 0);
	test_integer("%.3d", 0);
	test_integer("%05.0d", 0);
	test_integer("%.0d", 42);
	printf("\n========== SIGN FLAGS ==========\n");
	test_integer("%+d", 42);
	test_integer("%+d", -42);
	test_integer("% d", 42);
	test_integer("% d", -42);
	test_integer("%+ d", 42);
	test_integer("%+8d", 42);
	test_integer("%+08d", 42);
	test_integer("% 08d", 42);
	test_integer("%+.5d", 42);
	test_integer("%+.0d", 0);
	test_integer("% .0d", 0);
	test_integer("%+08.3d", 42);
	return (0);
}
