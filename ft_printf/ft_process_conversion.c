/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 00:34:04 by username          #+#    #+#             */
/*   Updated: 2026/11/03 02:04:34 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch_unsigned(char c, unsigned int n)
{
	int	written;

	written = -1;
	if (c == 'u')
		written = ft_write_unsigned(n);
	else if (c == 'x')
		written = ft_write_hexa_low(n);
	else if (c == 'X')
		written = ft_write_hexa_up(n);
	return (written);
}

int	ft_process_conversion(const char **chaine, va_list *args)
{
	int	written;

	written = -1;
	(*chaine)++;
	if (**chaine == 'd' || **chaine == 'i')
		written = ft_write_integer(va_arg(*args, int));
	else if (**chaine == 'u' || **chaine == 'x' || **chaine == 'X')
		written = ft_dispatch_unsigned(**chaine, va_arg(*args, unsigned int));
	else if (**chaine == 'c')
		written = ft_write_char(va_arg(*args, int));
	else if (**chaine == 's')
		written = ft_write_string(va_arg(*args, char *));
	else if (**chaine == 'p')
		written = ft_write_ptr(va_arg(*args, void *));
	else if (**chaine == '%')
		written = ft_write_char('%');
	if (written >= 0)
		(*chaine)++;
	return (written);
}
