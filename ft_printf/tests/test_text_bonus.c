/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_text_bonus.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 01:16:41 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:18:08 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include <stdio.h>

static void	test_char(const char *fmt, int c)
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
	expected = printf(fmt, c);
	printf("] (%d)\n", expected);
	printf("ft_format : [");
	fflush(stdout);
	actual = ft_format_char(c, &format);
	printf("] (%d)\n", actual);
}

static void	test_string(const char *fmt, const char *str)
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
	expected = printf(fmt, str);
	printf("] (%d)\n", expected);
	printf("ft_format : [");
	fflush(stdout);
	actual = ft_format_string(str, &format);
	printf("] (%d)\n", actual);
}

int	main(void)
{
	printf("========== CHARACTERS ==========\n");
	test_char("%c", 'A');
	test_char("%5c", 'A');
	test_char("%-5c", 'A');
	test_char("%1c", 'A');
	test_char("%10c", 'Z');
	test_char("%5c", '\0');
	printf("\n========== STRINGS ==========\n");
	test_string("%s", "Bonjour");
	test_string("%10s", "Bonjour");
	test_string("%-10s", "Bonjour");
	test_string("%.3s", "Bonjour");
	test_string("%.10s", "Bonjour");
	test_string("%10.3s", "Bonjour");
	test_string("%-10.3s", "Bonjour");
	test_string("%.0s", "Bonjour");
	test_string("%10s", "");
	test_string("%s", NULL);
	return (0);
}
