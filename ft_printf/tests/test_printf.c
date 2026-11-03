/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 03:44:20 by username          #+#    #+#             */
/*   Updated: 2026/11/03 03:57:46 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	expected;
	int	actual;
	int	n;

	n = 42;
	printf("========== STRINGS ==========\n");
	expected = printf("Hello %s!\n", "42");
	fflush(stdout);
	actual = ft_printf("Hello %s!\n", "42");
	printf("Expected: %d | Actual: %d\n\n", expected, actual);
	printf("========== SIGNED ==========\n");
	expected = printf("%d %i\n", INT_MIN, INT_MAX);
	fflush(stdout);
	actual = ft_printf("%d %i\n", INT_MIN, INT_MAX);
	printf("Expected: %d | Actual: %d\n\n", expected, actual);
	printf("========== UNSIGNED ==========\n");
	expected = printf("%u\n", UINT_MAX);
	fflush(stdout);
	actual = ft_printf("%u\n", UINT_MAX);
	printf("Expected: %d | Actual: %d\n\n", expected, actual);
	printf("========== HEXADECIMAL ==========\n");
	expected = printf("%x %X\n", UINT_MAX, UINT_MAX);
	fflush(stdout);
	actual = ft_printf("%x %X\n", UINT_MAX, UINT_MAX);
	printf("Expected: %d | Actual: %d\n\n", expected, actual);
	printf("========== POINTER ==========\n");
	expected = printf("%p\n", (void *) & n);
	fflush(stdout);
	actual = ft_printf("%p\n", (void *) & n);
	printf("Expected: %d | Actual: %d\n\n", expected, actual);
	printf("========== PERCENT ==========\n");
	expected = printf("100%% correct\n");
	fflush(stdout);
	actual = ft_printf("100%% correct\n");
	printf("Expected: %d | Actual: %d\n\n", expected, actual);
	printf("========== CHAR ==========\n");
	expected = printf("%c\n", 'A');
	fflush(stdout);
	actual = ft_printf("%c\n", 'A');
	printf("Expected: %d | Actual: %d\n\n", expected, actual);
	printf("========== NULL ==========\n");
	actual = ft_printf("%s %p\n", (char *) NULL, (void *) NULL);
	printf("ft_printf returned: %d\n", actual);
	printf("\n========== EDGE CASES ==========\n");
	printf("Original : [%s]\n", "");
	ft_printf("Custom   : [%s]\n", "");
	printf("Original : [%d]\n", 0);
	ft_printf("Custom   : [%d]\n", 0);
	printf("Original : [%x]\n", 0U);
	ft_printf("Custom   : [%x]\n", 0U);
	printf("Original : [%c]\n", '\0');
	ft_printf("Custom   : [%c]\n", '\0');
	printf("Original : [%s %d %x %c %%]\n", "42", -42, 255U, 'A');
	ft_printf("Custom   : [%s %d %x %c %%]\n", "42", -42, 255U, 'A');
	printf("Empty format: %d\n", ft_printf(""));
	return (0);
}
