/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:45:13 by username          #+#    #+#             */
/*   Updated: 2024/09/24 16:47:31 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

static void	ft_putdec(unsigned long ulong)
{
	char			*base;

	base = "0123456789";
	if (ulong < (unsigned long)10)
		ft_putchar_fd(base[ulong], 1);
	if (ulong >= (unsigned long)10)
	{
		ft_putdec(ulong / 10);
		ft_putdec(ulong % 10);
	}
}

int	print_udc(unsigned long ulong, t_flags flags)
{
	int	count;
	int	base_count;

	count = get_digits(ulong, 10);
	base_count = count;
	if (flags.minus)
	{
		if (flags.precision >= 0)
			count += pad(flags.precision - base_count, 1);
		ft_putdec(ulong);
	}
	if (flags.precision >= 0 && flags.precision < count)
		flags.precision = count;
	if (flags.precision >= 0)
		count += pad((flags.width - flags.precision), flags.zero);
	else
		count += pad(flags.width - count, flags.zero);
	if (!flags.minus)
	{
		if (flags.precision >= 0)
			count += pad(flags.precision - base_count, 1);
		ft_putdec(ulong);
	}
	return (count);
}

static int	print_nbr_flags(int n, t_flags flags)
{
	int	count;

	count = 0;
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
	if (!flags.zero)
		count += print_nbr_flags(n, flags);
	if (flags.precision >= 0)
		count += nbr_pad(n, flags);
	ft_putdec(unb);
	return (count);
}

int	print_nbr(int n, t_flags flags)
{
	unsigned int	unb;
	int				count;

	if (n < 0)
		unb = n * -1;
	else
		unb = (unsigned int)n;
	count = get_digits((unsigned long)unb, 10);
	if (flags.zero)
		count += print_nbr_flags(n, flags);
	if (flags.minus)
		count += print_pre(n, unb, flags);
	if (flags.precision >= 0)
		count += pad(flags.width - flags.precision, flags.zero);
	else
	{
		if ((n < 0 || ((n >= 0) && (flags.plus || flags.space))) && \
		!flags.zero && !flags.minus)
			count += pad(flags.width - (count + 1), flags.zero);
		count += pad(flags.width - count, flags.zero);
	}
	if (!flags.minus)
		count += print_pre(n, unb, flags);
	return (count);
}
