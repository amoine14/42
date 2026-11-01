/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/01 15:39:29 by username         #+#    #+#              */
/*   Updated: 2026/11/01 16:09:49 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_format
{
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

int			ft_printf(const char *format, ...);
t_format	ft_define_format(const char *str);

#endif
