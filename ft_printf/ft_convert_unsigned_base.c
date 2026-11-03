/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 02:05:26 by username          #+#    #+#             */
/*   Updated: 2026/11/03 02:45:46 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_base_digits(unsigned long n, int base_len)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

int ft_convert_unsigned_base(unsigned long int n,
	const char	*base, char *tab)
{
	int	base_len;
	int	i;
	int	len;
	base_len = ft_strlen(base);

	if (n == 0)
	{
		tab[0] = base[0];
		tab[1] = '\0';
		return (1);
	}
	i = ft_count_base_digits(n, base_len);
	len = i;
	tab[i] = '\0';
	while (i > 0)
	{
		i--;
		tab[i] = base[n % base_len];
		n /= base_len;
	}
	return (len);
}
