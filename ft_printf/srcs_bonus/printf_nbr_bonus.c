/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:51:37 by username          #+#    #+#             */
/*   Updated: 2024/09/24 10:54:08 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

void	ft_putcount_dec(unsigned long ulong, int *count)
{
	char			*base;

	base = "0123456789";
	if (ulong < (unsigned long)10)
	{
		ft_putchar_fd(base[ulong], 1);
		(*count)++;
	}
	if (ulong >= (unsigned long)10)
	{
		ft_putcount_dec(ulong / 10, count);
		ft_putcount_dec(ulong % 10, count);
	}
}

int	ft_putcount_nbr(int n)
{
	unsigned int	unb;

	ft_putnbr_fd(n, 1);
	if (n < 0)
		unb = n * -1;
	else
		unb = (unsigned int)n;
	return (get_digits(unb) + (n < 0));
}
