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
