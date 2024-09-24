/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:02:07 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/24 10:53:20 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

int	get_digits(unsigned int n)
{
	size_t	digits;

	digits = 1;
	while (n / 10 > 0)
	{
		digits++;
		n /= 10;
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
