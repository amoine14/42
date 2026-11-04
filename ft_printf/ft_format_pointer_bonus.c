/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_format_pointer_bonus.c                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 01:12:42 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:12:43 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

typedef struct s_pointer_parts
{
	char	buffer[65];
	int		digits;
	int		zeros;
	int		spaces;
}	t_pointer_parts;

static void ft_prepare_pointer(void * ptr, t_printf_format * fmt,
	t_pointer_parts	*part)
{
	part->digits = ft_convert_unsigned_base((unsigned long) ptr,
		"0123456789abcdef", part->buffer);
	part->zeros = 0;
	if (fmt->precision_specified && fmt->precision > part->digits)
		part->zeros = fmt->precision - part->digits;
	part->spaces = fmt->width - part->digits - part->zeros - 2;
	if (part->spaces < 0)
		part->spaces = 0;
	if (fmt->zero_padding && !fmt->left_align
			&& !fmt->precision_specified)
	{
		part->zeros += part->spaces;
		part->spaces = 0;
	}
}

static int	ft_write_pointer_body(t_pointer_parts *part)
{
	if (write(1, "0x", 2) != 2)
		return (-1);
	if (ft_write_padding(part->zeros, '0') < 0)
		return (-1);
	if (write(1, part->buffer, part->digits) != part->digits)
		return (-1);
	return (2 + part->zeros + part->digits);
}

static int	ft_write_null_pointer(t_printf_format *fmt)
{
	int	spaces;

	spaces = fmt->width - 5;
	if (spaces < 0)
		spaces = 0;
	if (!fmt->left_align && ft_write_padding(spaces, ' ') < 0)
		return (-1);
	if (write(1, "(nil)", 5) != 5)
		return (-1);
	if (fmt->left_align && ft_write_padding(spaces, ' ') < 0)
		return (-1);
	return (spaces + 5);
}

int	ft_format_pointer(void *ptr, t_printf_format *fmt)
{
	t_pointer_parts	part;
	int				written;

	if (!ptr)
		return (ft_write_null_pointer(fmt));
	ft_prepare_pointer(ptr, fmt, &part);
	if (!fmt->left_align && ft_write_padding(part.spaces, ' ') < 0)
		return (-1);
	written = ft_write_pointer_body(&part);
	if (written < 0)
		return (-1);
	if (fmt->left_align && ft_write_padding(part.spaces, ' ') < 0)
		return (-1);
	return (written + part.spaces);
}
