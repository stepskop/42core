/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:45:13 by username          #+#    #+#             */
/*   Updated: 2024/09/26 21:11:26 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

static int	nbr_pad(int n, t_flags flags)
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

static int	print_nbr_flags(int n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision == 0 && n == 0)
		return (0);
	if (flags.plus && n >= 0)
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	else if (flags.space && n >= 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
	}
	return (count);
}

static int	print_pre(int n, unsigned int unb, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision == 0 && n == 0)
		return (0);
	if (!flags.zero)
		count += print_nbr_flags(n, flags);
	if (flags.precision >= 0)
		count += nbr_pad(n, flags);
	putdec(unb);
	return (count);
}

int	print_nbr(int n, t_flags flags)
{
	unsigned int	unb;
	int				count;
	int				p;

	p = (!flags.minus && (n < 0 || ((n >= 0) && (flags.plus || flags.space))));
	unb = to_uint(n);
	count = get_digits((unsigned long)unb, 10);
	if (flags.precision == 0 && n == 0)
		count--;
	if (flags.zero)
		count += print_nbr_flags(n, flags);
	if (flags.minus)
		count += print_pre(n, unb, flags);
	if (flags.precision >= 0)
	{
		if (flags.precision < count)
			count += pad(flags.width - (count + p), 0);
		else
			count += pad(flags.width - flags.precision, 0);
	}
	else
		count += pad(flags.width - (count + (p && !flags.zero)), flags.zero);
	if (!flags.minus)
		count += print_pre(n, unb, flags);
	return (count);
}
