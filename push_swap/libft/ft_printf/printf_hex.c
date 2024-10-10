/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:51:25 by username          #+#    #+#             */
/*   Updated: 2024/09/26 21:44:16 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned long ulong, unsigned int toupper)
{
	char			*base;

	base = "0123456789abcdef";
	if (ulong < (unsigned long)16)
	{
		if (toupper && (base[ulong] >= 97 && base[ulong] <= 122))
			ft_putchar_fd(base[ulong] - 32, 1);
		else
			ft_putchar_fd(base[ulong], 1);
	}
	if (ulong >= (unsigned long)16)
	{
		ft_puthex(ulong / 16, toupper);
		ft_puthex(ulong % 16, toupper);
	}
}

static int	print_pre(unsigned long ulong, unsigned int tppr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision == 0 && ulong == 0)
		return (0);
	if (flags.h_tag && ulong != 0)
	{
		if (tppr)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		count += 2;
	}
	if (flags.precision >= 0)
		count += hex_pad(ulong, flags);
	ft_puthex(ulong, tppr);
	return (count);
}

int	print_hex(unsigned long u, unsigned int t, t_flags f)
{
	int	count;
	int	p;

	p = 2 * (!f.minus && (f.h_tag && u != 0));
	count = get_digits(u, 16);
	if (f.precision == 0 && u == 0)
		count--;
	if (f.minus)
		count += print_pre(u, t, f);
	if (f.precision >= 0)
	{
		if (f.precision < count)
			count += pad(f.width - (count + p), 0);
		else
			count += pad(f.width - (f.precision + p), 0);
	}
	else
		count += pad(f.width - (count + p), f.zero);
	if (!f.minus)
		count += print_pre(u, t, f);
	return (count);
}

static int	print_nullptr(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
		ft_putstr_fd("(nil)", 1);
	count += pad(flags.width - 5, 0);
	if (!flags.minus)
		ft_putstr_fd("(nil)", 1);
	return (count + 5);
}

int	print_ptr(void *ptr, t_flags flags)
{
	int	count;

	count = 0;
	if (ptr)
	{
		count = get_digits((unsigned long)ptr, 16) + 2;
		if (flags.minus)
		{
			write(1, "0x", 2);
			count += pad((flags.width - count) * flags.zero, 1);
			ft_puthex((unsigned long)ptr, 0);
		}
		count += pad((flags.width - count) * (!flags.zero), 0);
		if (!flags.minus)
		{
			write(1, "0x", 2);
			count += pad((flags.width - count) * flags.zero, 1);
			ft_puthex((unsigned long)ptr, 0);
		}
	}
	else
		count = print_nullptr(flags);
	return (count);
}
