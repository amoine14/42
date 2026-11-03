/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_bonus.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 14:58:55 by username         #+#    #+#              */
/*   Updated: 2026/11/03 14:58:56 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include <stdio.h>

static void	test_format(const char *input)
{
	const char		*cursor;
	t_printf_format	format;
	int				result;

	cursor = input;
	result = ft_parse_format(&cursor, &format);
	printf("\n========== TEST [%s] ==========\n", input);
	if (!result)
	{
		printf("INVALID FORMAT\n");
		return ;
	}
	printf("left_align          = %d\n", format.left_align);
	printf("zero_padding        = %d\n", format.zero_padding);
	printf("alternate_form      = %d\n", format.alternate_form);
	printf("force_sign          = %d\n", format.force_sign);
	printf("space_sign          = %d\n", format.space_sign);
	printf("width               = %d\n", format.width);
	printf("precision           = %d\n", format.precision);
	printf("precision_specified = %d\n", format.precision_specified);
	printf("conversion          = '%c'\n", format.conversion);
	printf("remaining string    = \"%s\"\n", cursor);
}

int	main(void)
{
	test_format("08.3d");
	test_format("-+#12.5x");
	test_format(".0d");
	test_format("10s");
	test_format("p");
	test_format("08.d");
	test_format("0005d");
	test_format("-+ 7XBonjour");
	test_format("%");
	test_format("q");
	test_format("");
	return (0);
}
