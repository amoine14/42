/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_parse_format_bonus.c                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 14:42:14 by username         #+#    #+#              */
/*   Updated: 2026/11/03 14:56:37 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_is_conversion(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	else if (c == 'u' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'c' || c == 's' || c == 'p')
		return (1);
	else if (c == '%')
		return (1);
	return (0);
}

int	ft_parse_format(const char **chaine, t_printf_format *format)
{
	ft_init_format(format);
	ft_parse_flags(chaine, format);
	ft_parse_width(chaine, format);
	ft_parse_precision(chaine, format);
	if (!ft_is_conversion(**chaine))
		return (0);
	format->conversion = **chaine;
	(*chaine)++;
	return (1);
}
