/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_printf_bonus.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 01:20:40 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:20:40 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	expected;
	int	actual;

	printf("========== BONUS INTEGRATION ==========\n\n");
	expected = printf("Nombre : %+08d | Hexa : %#x\n", 42, 255);
	actual = ft_printf("Nombre : %+08d | Hexa : %#x\n", 42, 255);
	printf("Expected: %d | Actual: %d\n\n", expected, actual);
	expected = printf("Texte : %-10.5s | Nombre : %08d\n",
		"Bonjour", -42);
	actual = ft_printf("Texte : %-10.5s | Nombre : %08d\n",
		"Bonjour", -42);
	printf("Expected: %d | Actual: %d\n\n", expected, actual);
	expected = printf("INT_MIN : %+.15d\n", INT_MIN);
	actual = ft_printf("INT_MIN : %+.15d\n", INT_MIN);
	printf("Expected: %d | Actual: %d\n", expected, actual);
	return (0);
}
