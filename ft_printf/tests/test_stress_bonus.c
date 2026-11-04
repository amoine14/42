/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_stress_bonus.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 01:42:41 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:43:29 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	show_result(int expected, int actual)
{
	if (expected == actual)
		printf("RESULT : OK (%d caractères)\n", actual);
	else
		printf("RESULT : FAIL (expected %d, got %d)\n",
		expected, actual);
}

static void	test_signed(const char *format, int n)
{
	int	expected;
	int	actual;

	printf("\nFORMAT : [%s] | n = %d\n", format, n);
	printf("printf    : [");
	fflush(stdout);
	expected = printf(format, n);
	printf("] (%d)\n", expected);
	printf("ft_printf : [");
	fflush(stdout);
	actual = ft_printf(format, n);
	printf("] (%d)\n", actual);
	show_result(expected, actual);
}

static void	test_unsigned(const char *format, unsigned int n)
{
	int	expected;
	int	actual;

	printf("\nFORMAT : [%s] | n = %u\n", format, n);
	printf("printf    : [");
	fflush(stdout);
	expected = printf(format, n);
	printf("] (%d)\n", expected);
	printf("ft_printf : [");
	fflush(stdout);
	actual = ft_printf(format, n);
	printf("] (%d)\n", actual);
	show_result(expected, actual);
}

static void	test_string(const char *format, const char *str)
{
	int	expected;
	int	actual;

	printf("\nFORMAT : [%s]\n", format);
	printf("printf    : [");
	fflush(stdout);
	expected = printf(format, str);
	printf("] (%d)\n", expected);
	printf("ft_printf : [");
	fflush(stdout);
	actual = ft_printf(format, str);
	printf("] (%d)\n", actual);
	show_result(expected, actual);
}

static void	test_pointer(const char *format, void *ptr)
{
	int	expected;
	int	actual;

	printf("\nFORMAT : [%s]\n", format);
	printf("printf    : [");
	fflush(stdout);
	expected = printf(format, ptr);
	printf("] (%d)\n", expected);
	printf("ft_printf : [");
	fflush(stdout);
	actual = ft_printf(format, ptr);
	printf("] (%d)\n", actual);
	show_result(expected, actual);
}

static void	test_character(const char *format, int c)
{
	int	expected;
	int	actual;

	printf("\nFORMAT : [%s]\n", format);
	printf("printf    : [");
	fflush(stdout);
	expected = printf(format, c);
	printf("] (%d)\n", expected);
	printf("ft_printf : [");
	fflush(stdout);
	actual = ft_printf(format, c);
	printf("] (%d)\n", actual);
	show_result(expected, actual);
}

static void	test_mixed(int *n)
{
	int	expected;
	int	actual;

	printf("\n========== MIXED TEST 1 ==========\n");
	expected = printf("%+08d | %#x | %-10.5s\n",
		42, 255U, "Bonjour");
	actual = ft_printf("%+08d | %#x | %-10.5s\n",
		42, 255U, "Bonjour");
	show_result(expected, actual);
	printf("\n========== MIXED TEST 2 ==========\n");
	expected = printf("%p | %d | %u | %X\n",
		(void *) n, -42, 42U, 255U);
	actual = ft_printf("%p | %d | %u | %X\n",
		(void *) n, -42, 42U, 255U);
	show_result(expected, actual);
	printf("\n========== MIXED TEST 3 ==========\n");
	expected = printf("%-10c | %+010d | %#010x\n",
		'A', -42, 255U);
	actual = ft_printf("%-10c | %+010d | %#010x\n",
		'A', -42, 255U);
	show_result(expected, actual);
	printf("\n========== MIXED TEST 4 ==========\n");
	expected = printf("%s | %c | %d | %p\n",
		"42", 'X', INT_MIN, (void *) NULL);
	actual = ft_printf("%s | %c | %d | %p\n",
		"42", 'X', INT_MIN, (void *) NULL);
	show_result(expected, actual);
}

int	main(void)
{
	int		n;
	char	*null_str;

	n = 42;
	null_str = NULL;
	printf("\n========== SIGNED INTEGERS ==========\n");
	test_signed("%+010d", 42);
	test_signed("% 010d", 42);
	test_signed("%-+10d", 42);
	test_signed("%+10.5d", 42);
	test_signed("%010.5d", -42);
	test_signed("%-+10.5d", 42);
	test_signed("%+05.0d", 0);
	test_signed("%10.0d", 0);
	test_signed("%+.15d", INT_MIN);
	test_signed("%020d", INT_MAX);
	test_signed("%020d", INT_MIN);
	printf("\n========== UNSIGNED INTEGERS ==========\n");
	test_unsigned("%020u", UINT_MAX);
	test_unsigned("%-15.10u", 42U);
	test_unsigned("%015.10u", 42U);
	test_unsigned("%.0u", 0U);
	test_unsigned("%10.0u", 0U);
	printf("\n========== HEXADECIMAL ==========\n");
	test_unsigned("%#020x", UINT_MAX);
	test_unsigned("%#020X", UINT_MAX);
	test_unsigned("%-#20.10x", 255U);
	test_unsigned("%#020.10X", 255U);
	test_unsigned("%#010x", 0U);
	test_unsigned("%#.0x", 0U);
	test_unsigned("%#15.0x", 0U);
	test_unsigned("%#x", 255U);
	test_unsigned("%#X", 255U);
	printf("\n========== STRINGS ==========\n");
	test_string("%20.5s", "Bonjour");
	test_string("%-20.5s", "Bonjour");
	test_string("%.0s", "Bonjour");
	test_string("%10.3s", null_str);
	test_string("%10.6s", null_str);
	test_string("%-10s", "");
	test_string("%20s", "42");
	printf("\n========== POINTERS ==========\n");
	test_pointer("%20p", (void *) & n);
	test_pointer("%-20p", (void *) & n);
	test_pointer("%020p", (void *) & n);
	test_pointer("%20p", NULL);
	test_pointer("%-20p", NULL);
	printf("\n========== CHARACTERS ==========\n");
	test_character("%10c", 'A');
	test_character("%-10c", 'Z');
	test_character("%5c", '\0');
	test_mixed(&n);
	printf("\n========== END OF TESTS ==========\n");
	return (0);
}
