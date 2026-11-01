/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 15:39:29 by username          #+#    #+#             */
/*   Updated: 2026/11/01 15:45:58 by axel             ###   ########.fr       */
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

int	ft_printf(const char *format, ...);

#endif
