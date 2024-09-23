/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:02:07 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/23 21:49:59 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

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

int	print_pre(char *s, int precision)
{
	int	count;

	count = 0;
	if (precision < 0)
	{
		while (s[count])
			ft_putchar_fd(s[count++], 1);
		return (count);
	}
	while (s[count] && count <= precision)
		ft_putchar_fd(s[count++], 1);
	return (count);
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

int	ft_putcount_str(char *s, t_flags flags)
{
	int	count;

	count = 0;
	if (!s && flags.precision < 6)
		return (pad(flags.width, 0));
	if (!s)
		s = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(s))
		flags.precision = (int)ft_strlen(s);
	if (flags.minus)
		count += print_pre(s, flags.precision);
	if (flags.precision >= 0)
		count += pad(flags.width - flags.precision, 0);
	else
		count += pad(flags.width - ft_strlen(s), 0);
	if (!flags.minus)
		count += print_pre(s, flags.precision);
	return (count);
}

int	ft_putcount_chr(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		ft_putchar_fd(c, 1);
		count++;
	}
	count += pad(flags.width - 1, flags.zero);
	if (!flags.minus)
	{
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
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
