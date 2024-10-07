/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:02:07 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/26 21:15:49 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_digits(unsigned long n, unsigned int base)
{
	size_t	digits;

	digits = 1;
	while (n / base > 0)
	{
		digits++;
		n /= base;
	}
	return (digits);
}

int	pad(int size, int zero)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (size < 0)
		return (0);
	return (size);
}

int	hex_pad(unsigned long ulong, t_flags flags)
{
	return (pad(flags.precision - get_digits(ulong, 16), 1));
}

unsigned int	to_uint(int n)
{
	if (n < 0)
		return (-n);
	else
		return ((unsigned int)n);
}

void	putdec(unsigned long ulong)
{
	char			*base;

	base = "0123456789";
	if (ulong < (unsigned long)10)
		ft_putchar_fd(base[ulong], 1);
	if (ulong >= (unsigned long)10)
	{
		putdec(ulong / 10);
		putdec(ulong % 10);
	}
}
