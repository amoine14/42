/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_parse_flags_bonus.c                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 14:06:02 by username         #+#    #+#              */
/*   Updated: 2026/11/03 14:41:31 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == '0')
		return (1);
	else if (c == ' ' || c == '#')
		return (1);
	return (0);
}

void	ft_parse_flags(const char **chaine, t_printf_format *format)
{
	while (**chaine && ft_is_flag(**chaine))
	{
		if (**chaine == '-')
			format->left_align = 1;
		else if (**chaine == '+')
			format->force_sign = 1;
		else if (**chaine == '0')
			format->zero_padding = 1;
		else if (**chaine == ' ')
			format->space_sign = 1;
		else if (**chaine == '#')
			format->alternate_form = 1;
		(*chaine)++;
	}
}
