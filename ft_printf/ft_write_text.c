/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 03:14:11 by username          #+#    #+#             */
/*   Updated: 2026/11/03 03:51:55 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(int c)
{
	char	character;

	character = (unsigned char) c;
	if (write(1, &character, 1) != 1)
		return (-1);
	return (1);
}

int	ft_write_string(const char *chaine)
{
	int	len;

	if (!chaine)
		chaine = "(null)";
	len = ft_strlen(chaine);
	if (write(1, chaine, len) != len)
		return (-1);
	return (len);
}
