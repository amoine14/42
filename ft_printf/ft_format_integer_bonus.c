/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_format_integer_bonus.c                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 16:12:33 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:04:56 by username        ###   ########.fr        */
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

static int	ft_precision_zeros(int n, t_printf_format *format)
{
	int	digits;
	int	zeros;

	if (!format->precision_specified)
		return (0);
	digits = ft_integer_length(n) - (n < 0);
	zeros = format->precision - digits;
	if (zeros < 0)
		zeros = 0;
	return (zeros);
}

static int	ft_integer_content_len(int n, t_printf_format *format)
{
	int	len;

	if (n == 0 && format->precision_specified
			&& format->precision == 0)
	len = 0;
	else
		len = ft_integer_length(n) + ft_precision_zeros(n, format);
	if (n >= 0 && ft_integer_sign(n, format) != '\0')
		len++;
	return (len);
}

static int ft_write_zero_integer(int n, int zeros,
	t_printf_format	*format)
{
	unsigned int	value;
	char			sign;
	int				digits;

	sign = ft_integer_sign(n, format);
	if (sign && ft_write_char(sign) != 1)
		return (-1);
	if (ft_write_padding(zeros, '0') != zeros)
		return (-1);
	if (n == 0 && format->precision_specified
			&& format->precision == 0)
	return (zeros + (sign != '\0'));
	if (n < 0)
		value = (unsigned int)(-(long) n);
	else
		value = (unsigned int) n;
	digits = ft_write_unsigned(value);
	if (digits < 0)
		return (-1);
	return (digits + zeros + (sign != '\0'));
}

int	ft_format_integer(int n, t_printf_format *format)
{
	int	need_space;
	int	max_len;

	max_len = ft_integer_content_len(n, format);
	need_space = format->width - max_len;
	if (need_space < 0)
		need_space = 0;
	if (format->zero_padding && !format->left_align
			&& !format->precision_specified)
	return (ft_write_zero_integer(n, need_space, format));
	if (!format->left_align && ft_write_padding(need_space, ' ') < 0)
		return (-1);
	if (ft_write_zero_integer(n, ft_precision_zeros(n, format),
				format) < 0)
	return (-1);
	if (format->left_align && ft_write_padding(need_space, ' ') < 0)
		return (-1);
	return (need_space + max_len);
}
