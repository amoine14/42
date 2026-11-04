/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_format_unsigned_bonus.c                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 01:08:28 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:08:28 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

typedef struct s_unsigned_parts
{
	char	buffer[65];
	int		digits;
	int		zeros;
	int		spaces;
	int		prefix;
}	t_unsigned_parts;

static void ft_setup_unsigned(unsigned int n, t_printf_format * fmt,
	t_unsigned_parts	*part)
{
	const char	*base;

	base = "0123456789";
	if (fmt->conversion == 'x')
		base = "0123456789abcdef";
	else if (fmt->conversion == 'X')
		base = "0123456789ABCDEF";
	part->digits = ft_convert_unsigned_base(n, base, part->buffer);
	if (n == 0 && fmt->precision_specified && fmt->precision == 0)
		part->digits = 0;
	part->prefix = 0;
	if (n && fmt->alternate_form && (fmt->conversion == 'x'
				|| fmt->conversion == 'X'))
	part->prefix = 2;
	part->zeros = 0;
	if (fmt->precision_specified && fmt->precision > part->digits)
		part->zeros = fmt->precision - part->digits;
}

static void ft_set_unsigned_padding(t_printf_format * fmt,
	t_unsigned_parts	*part)
{
	part->spaces = fmt->width - part->digits - part->zeros - part->prefix;
	if (part->spaces < 0)
		part->spaces = 0;
	if (fmt->zero_padding && !fmt->left_align
			&& !fmt->precision_specified)
	{
		part->zeros += part->spaces;
		part->spaces = 0;
	}
}

static int ft_write_unsigned_body(t_unsigned_parts * part,
	t_printf_format	*fmt)
{
	if (part->prefix && fmt->conversion == 'x'
			&& write(1, "0x", 2) != 2)
	return (-1);
	if (part->prefix && fmt->conversion == 'X'
			&& write(1, "0X", 2) != 2)
	return (-1);
	if (ft_write_padding(part->zeros, '0') < 0)
		return (-1);
	if (write(1, part->buffer, part->digits) != part->digits)
		return (-1);
	return (part->prefix + part->zeros + part->digits);
}

int	ft_format_unsigned(unsigned int n, t_printf_format *fmt)
{
	t_unsigned_parts	part;
	int					written;

	ft_setup_unsigned(n, fmt, &part);
	ft_set_unsigned_padding(fmt, &part);
	if (!fmt->left_align && ft_write_padding(part.spaces, ' ') < 0)
		return (-1);
	written = ft_write_unsigned_body(&part, fmt);
	if (written < 0)
		return (-1);
	if (fmt->left_align && ft_write_padding(part.spaces, ' ') < 0)
		return (-1);
	return (written + part.spaces);
}
