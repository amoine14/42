/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_bonus.h                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 13:48:07 by username         #+#    #+#              */
/*   Updated: 2026/11/03 16:12:41 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

typedef struct s_printf_format
{
	int		left_align;
	int		zero_padding;
	int		alternate_form;
	int		force_sign;
	int		space_sign;
	int		width;
	int		precision;
	int		precision_specified;
	char	conversion;
}	t_printf_format;

void	ft_init_format(t_printf_format *format);
void	ft_parse_flags(const char **chaine, t_printf_format *format);
void	ft_parse_width(const char **chaine, t_printf_format *format);
void	ft_parse_precision(const char **chaine, t_printf_format *format);
int		ft_parse_format(const char **chaine, t_printf_format *format);
int		ft_write_padding(int count, char character);
int		ft_format_char(int c, t_printf_format *format);
int		ft_format_string(const char *chaine, t_printf_format *format);
int		ft_format_integer(int n, t_printf_format *format);

#endif
