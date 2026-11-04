/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_format_text_bonus.c                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 15:10:31 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:28:15 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_format_char(int c, t_printf_format *format)
{
	int	need_space;

	need_space = format->width - 1;
	if (need_space < 0)
		need_space = 0;
	if (!format->left_align)
	{
		if (ft_write_padding(need_space, ' ') < 0)
			return (-1);
		if (ft_write_char(c) != 1)
			return (-1);
		return (need_space + 1);
	}
	if (ft_write_char(c) != 1)
		return (-1);
	if (ft_write_padding(need_space, ' ') < 0)
		return (-1);
	return (need_space + 1);
}

#include "ft_printf_bonus.h"

static int ft_write_aligned_string(const char * chaine, int len,
	t_printf_format	*format)
{
	int	need_space;

	need_space = format->width - len;
	if (need_space < 0)
		need_space = 0;
	if (!format->left_align && ft_write_padding(need_space, ' ') < 0)
		return (-1);
	if (write(1, chaine, len) != len)
		return (-1);
	if (format->left_align && ft_write_padding(need_space, ' ') < 0)
		return (-1);
	return (need_space + len);
}

int	ft_format_string(const char *chaine, t_printf_format *format)
{
	int	max_len;

	if (!chaine)
	{
		if (format->precision_specified && format->precision < 6)
			chaine = "";
		else
			chaine = "(null)";
	}
	max_len = (int) ft_strlen(chaine);
	if (format->precision_specified && format->precision < max_len)
		max_len = format->precision;
	return (ft_write_aligned_string(chaine, max_len, format));
}
