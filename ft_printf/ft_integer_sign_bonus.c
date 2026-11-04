/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_integer_sign_bonus.c                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 00:51:59 by username         #+#    #+#              */
/*   Updated: 2026/11/04 00:54:13 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	ft_integer_sign(int n, const t_printf_format *format)
{
	if (n < 0)
		return ('-');
	if (format->force_sign)
		return ('+');
	if (format->space_sign)
		return (' ');
	return ('\0');
}
