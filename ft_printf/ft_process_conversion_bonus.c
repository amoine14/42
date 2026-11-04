/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_process_conversion_bonus.c                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 01:19:35 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:19:36 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_dispatch_bonus_number(t_printf_format *format, va_list *args)
{
	char	c;

	c = format->conversion;
	if (c == 'd' || c == 'i')
		return (ft_format_integer(va_arg(*args, int), format));
	if (c == 'u' || c == 'x' || c == 'X')
		return (ft_format_unsigned(va_arg(*args, unsigned int), format));
	return (-1);
}

static int	ft_dispatch_bonus_text(t_printf_format *format, va_list *args)
{
	char	c;

	c = format->conversion;
	if (c == 'c')
		return (ft_format_char(va_arg(*args, int), format));
	if (c == 's')
		return (ft_format_string(va_arg(*args, char *), format));
	if (c == 'p')
		return (ft_format_pointer(va_arg(*args, void *), format));
	if (c == '%')
		return (ft_write_char('%'));
	return (-1);
}

int	ft_process_conversion(const char **chaine, va_list *args)
{
	t_printf_format	format;
	char			c;

	(*chaine)++;
	if (!ft_parse_format(chaine, &format))
		return (-1);
	c = format.conversion;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (ft_dispatch_bonus_number(&format, args));
	return (ft_dispatch_bonus_text(&format, args));
}
