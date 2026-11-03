/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_write_padding_bonus.c                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 15:05:19 by username         #+#    #+#              */
/*   Updated: 2026/11/03 15:10:01 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

int	ft_write_padding(int count, char character)
{
	int	written;

	written = 0;
	while (written < count)
	{
		if (write(1, &character, 1) != 1)
			return (-1);
		written++;
	}
	return (written);
}
