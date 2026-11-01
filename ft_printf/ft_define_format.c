/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_define_format.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/01 16:09:18 by username         #+#    #+#              */
/*   Updated: 2026/11/01 17:23:16 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_conversion_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

t_format set_flags

int	ft_define_format(const char *s, t_format *format)
{
	size_t	i;

	i = 0;
	while (s[i] && !(is_conversion_specifier(s[i])))
	{
		if (s[i] == '-')
			format->minus = 1;
		else if (s[i] == '0')
			format->zero = 1;
		else if (s[i] == '.')
			format->dot = 1;
		else if (s[i] == '#')
			format->hash = 1;
		else if (s[i] == '+')
			format->plus = 1;
		else if (s[i] == ' ')
			format->space = 1;
		else if (s[i] == '0')
			format->width = 1;
		else if (s[i] == '0')
			format->precision = 1;
		i++;
	}
	format->specifier = is_conversion_specifier(s[i]);
	return (format->specifier);
}
