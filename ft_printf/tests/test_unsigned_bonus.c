/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_unsigned_bonus.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 01:10:52 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:10:55 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

static void	test_unsigned(const char *fmt, unsigned int n)
{
	const char		*cursor;
	t_printf_format	format;
	int				expected;
	int				actual;

	cursor = fmt + 1;
	if (!ft_parse_format(&cursor, &format))
	{
		printf("INVALID FORMAT: %s\n", fmt);
		return ;
	}
	printf("\nFormat : [%s] | n = %u\n", fmt, n);
	printf("printf    : [");
	fflush(stdout);
	expected = printf(fmt, n);
	printf("] (%d)\n", expected);
	printf("ft_format : [");
	fflush(stdout);
	actual = ft_format_unsigned(n, &format);
	printf("] (%d)\n", actual);
}

int	main(void)
{
	printf("========== UNSIGNED ==========\n");
	test_unsigned("%u", 42U);
	test_unsigned("%u", UINT_MAX);
	test_unsigned("%8u", 42U);
	test_unsigned("%-8u", 42U);
	test_unsigned("%08u", 42U);
	test_unsigned("%.5u", 42U);
	test_unsigned("%.0u", 0U);
	printf("\n========== HEXADECIMAL ==========\n");
	test_unsigned("%x", 255U);
	test_unsigned("%X", 255U);
	test_unsigned("%x", UINT_MAX);
	test_unsigned("%X", UINT_MAX);
	test_unsigned("%#x", 255U);
	test_unsigned("%#X", 255U);
	test_unsigned("%#x", 0U);
	printf("\n========== FLAGS ==========\n");
	test_unsigned("%#08x", 255U);
	test_unsigned("%#08X", 255U);
	test_unsigned("%-#10x", 255U);
	test_unsigned("%#10.5x", 255U);
	test_unsigned("%08.3x", 42U);
	test_unsigned("%#.0x", 0U);
	test_unsigned("%10.0u", 0U);
	test_unsigned("%#x", UINT_MAX);
	return (0);
}
