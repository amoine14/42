/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_parse_width_bonus.c                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 14:23:21 by username         #+#    #+#              */
/*   Updated: 2026/11/03 14:41:29 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_parse_width(const char **chaine, t_printf_format *format)
{
	while (ft_isdigit(**chaine))
	{
		format->width = format->width * 10 + (**chaine - '0');
		(*chaine)++;
	}
}
