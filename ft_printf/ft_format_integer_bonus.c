/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_format_integer_bonus.c                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 16:12:33 by username         #+#    #+#              */
/*   Updated: 2026/11/03 18:12:13 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_integer_length(int n)
{
	int		count;
	long	value;

	if (n < 0)
		value = -(long) n;
	else
		value = (long) n;
	count = 0;
	while (value >= 10)
	{
		count++;
		value /= 10;
	}
	return (count + 1 + (n < 0));
}

static int	ft_write_zero_integer(int n, int zeros)
{
	unsigned int	value;
	int				digits;

	if (n < 0)
	{
		if (ft_write_char('-') != 1)
			return (-1);
		value = (unsigned int)(-(long) n);
	}
	else
		value = (unsigned int) n;
	if (ft_write_padding(zeros, '0') != zeros)
		return (-1);
	digits = ft_write_unsigned(value);
	if (digits < 0)
		return (-1);
	return (digits + zeros + (n < 0));
}

int	ft_format_integer(int n, t_printf_format *format)
{
	int	need_space;
	int	max_len;

	max_len = ft_integer_length(n);
	need_space = format->width - max_len;
	if (need_space < 0)
		need_space = 0;
	if (format->zero_padding && !format->left_align
			&& !format->precision_specified)
	return (ft_write_zero_integer(n, need_space));
	if (!format->left_align && ft_write_padding(need_space, ' ') < 0)
		return (-1);
	if (ft_write_integer(n) != max_len)
		return (-1);
	if (format->left_align && ft_write_padding(need_space, ' ') < 0)
		return (-1);
	return (need_space + max_len);
}
