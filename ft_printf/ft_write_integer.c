/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 01:30:05 by username          #+#    #+#             */
/*   Updated: 2026/11/03 03:46:49 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_integer(int n)
{
	char			tab[65];
	unsigned long	value;
	int				len;

	if (n < 0)
		value = (unsigned long)(-(long) n);
	else
		value = (unsigned long) n;
	len = ft_convert_unsigned_base(value, "0123456789", tab);
	if (n < 0 && write(1, "-", 1) != 1)
		return (-1);
	if (write(1, tab, len) != len)
		return (-1);
	return (len + (n < 0));
}

int	ft_write_unsigned(unsigned int n)
{
	char	tab[65];
	int		len;

	len = ft_convert_unsigned_base(n, "0123456789", tab);
	if (write(1, tab, len) != len)
		return (-1);
	return (len);
}

int	ft_write_hexa_low(unsigned int n)
{
	char	tab[65];
	int		len;

	len = ft_convert_unsigned_base(n, "0123456789abcdef", tab);
	if (write(1, tab, len) != len)
		return (-1);
	return (len);
}

int	ft_write_hexa_up(unsigned int n)
{
	char	tab[65];
	int		len;

	len = ft_convert_unsigned_base(n, "0123456789ABCDEF", tab);
	if (write(1, tab, len) != len)
		return (-1);
	return (len);
}
