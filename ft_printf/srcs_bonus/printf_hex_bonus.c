/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:51:25 by username          #+#    #+#             */
/*   Updated: 2024/09/24 11:33:02 by username         ###   ########.fr       */
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

void	ft_print_pointer(void *ptr, int *count)
{
	if (ptr)
	{
		write(1, "0x", 2);
		(*count) += 2;
		ft_putcount_hex((unsigned long)ptr, 0, count);
	}
	else
	{
		write(1, "(nil)", 5);
		(*count) += 5;
	}
}
