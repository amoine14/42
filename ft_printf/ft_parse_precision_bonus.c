/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_parse_precision_bonus.c                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 14:41:02 by username         #+#    #+#              */
/*   Updated: 2026/11/03 14:41:25 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_parse_precision(const char **chaine, t_printf_format *format)
{
	if (**chaine != '.')
		return ;
	format->precision_specified = 1;
	(*chaine)++;
	while (ft_isdigit(**chaine))
	{
		format->precision = format->precision * 10 + (**chaine - '0');
		(*chaine)++;
	}
}
