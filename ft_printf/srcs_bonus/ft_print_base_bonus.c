/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:32:42 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/21 20:55:30 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

void	ft_putcount_hex(unsigned long ulong, unsigned int toupper, int *count)
{
	char			*base;

	base = "0123456789abcdef";
	if (ulong < (unsigned long)16)
	{
		if (toupper && (base[ulong] >= 97 && base[ulong] <= 122))
			ft_putchar_fd(base[ulong] - 32, 1);
		else
			ft_putchar_fd(base[ulong], 1);
		(*count)++;
	}
	if (ulong >= (unsigned long)16)
	{
		ft_putcount_hex(ulong / 16, toupper, count);
		ft_putcount_hex(ulong % 16, toupper, count);
	}
}

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
