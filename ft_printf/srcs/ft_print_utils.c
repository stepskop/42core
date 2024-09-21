/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:02:07 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/21 19:51:26 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_digits(unsigned int n)
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

int	ft_putcount_str(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return ((int)ft_strlen(s));
}

int	ft_putcount_chr(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
