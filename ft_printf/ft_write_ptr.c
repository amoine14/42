/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 03:47:30 by username          #+#    #+#             */
/*   Updated: 2026/11/03 03:47:42 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_ptr(void *ptr)
{
	char			tab[65];
	unsigned long	address;
	int				len;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) != 5)
			return (-1);
		return (5);
	}
	address = (unsigned long) ptr;
	len = ft_convert_unsigned_base(address, "0123456789abcdef", tab);
	if (write(1, "0x", 2) != 2)
		return (-1);
	if (write(1, tab, len) != len)
		return (-1);
	return (len + 2);
}
