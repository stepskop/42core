/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:02:07 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/24 11:25:53 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

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

int	nbr_pad(int n, t_flags flags)
{
	unsigned int	unb;
	int				ds;
	int				count;

	count = 0;
	if (n < 0)
		unb = n * -1;
	else
		unb = (unsigned int)n;
	ds = get_digits((unsigned long)unb, 10);
	count += pad((flags.precision) - ds, 1);
	return (count);
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
