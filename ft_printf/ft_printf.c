/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 00:58:07 by username          #+#    #+#             */
/*   Updated: 2026/11/03 01:22:32 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_literal(const char **chaine)
{
	if (write(1, *chaine, 1) != 1)
		return (-1);
	(*chaine)++;
	return (1);
}

int	ft_printf(const char *chaine, ...)
{
	va_list	args;
	int		written;
	int		count;

	count = 0;
	va_start(args, chaine);
	while (*chaine)
	{
		if (*chaine != '%')
			written = ft_write_literal(&chaine);
		else
			written = ft_process_conversion(&chaine, &args);
		if (written < 0)
		{
			count = -1;
			break ;
		}
		count += written;
	}
	va_end(args);
	return (count);
}
