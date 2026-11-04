/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_write_error.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 01:44:05 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:44:05 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	saved_stdout;
	int	result;

	saved_stdout = dup(STDOUT_FILENO);
	if (saved_stdout == -1)
		return (1);
	close(STDOUT_FILENO);
	result = ft_printf("Hello %d", 42);
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
	{
		close(saved_stdout);
		return (1);
	}
	close(saved_stdout);
	printf("ft_printf returned: %d\n", result);
	printf("Expected: -1\n");
	return (result != -1);
}
