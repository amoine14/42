/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_init_format_bonus.c                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 13:54:55 by username         #+#    #+#              */
/*   Updated: 2026/11/03 13:58:54 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_format(t_printf_format *format)
{
	format->left_align = 0;
	format->zero_padding = 0;
	format->alternate_form = 0;
	format->force_sign = 0;
	format->space_sign = 0;
	format->width = 0;
	format->precision = 0;
	format->precision_specified = 0;
	format->conversion = '\0';
}
