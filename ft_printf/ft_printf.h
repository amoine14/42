/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 00:02:00 by username          #+#    #+#             */
/*   Updated: 2026/11/03 03:25:38 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

/* Fonction principale */
int	ft_printf(const char *chaine, ...);

/* Gestion des conversions */
int	ft_process_conversion(const char **chaine, va_list *args);

/* Conversion numérique */
int ft_convert_unsigned_base(unsigned long n,
	const char	*base, char *tab);

/* Affichage des nombres */
int	ft_write_integer(int n);
int	ft_write_unsigned(unsigned int n);
int	ft_write_hexa_low(unsigned int n);
int	ft_write_hexa_up(unsigned int n);

/* Affichage des caractères et chaînes */
int	ft_write_char(int c);
int	ft_write_string(const char *chaine);

/* Affichage des pointeurs */
int	ft_write_ptr(void *ptr);

#endif
