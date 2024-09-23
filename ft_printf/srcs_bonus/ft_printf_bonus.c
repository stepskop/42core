/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:02:49 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/23 21:02:59 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

static void	print_pointer(void *ptr, int *count)
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

static int	process_format(int *count, t_flags flags, va_list args)
{
	if (flags.conv == 'c')
		(*count) += ft_putcount_chr(va_arg(args, int), flags);
	else if (flags.conv == 's')
		(*count) += ft_putcount_str(va_arg(args, char *), flags);
	else if (flags.conv == 'p')
		print_pointer(va_arg(args, void *), count);
	else if (flags.conv == 'd' || flags.conv == 'i')
		(*count) += ft_putcount_nbr(va_arg(args, int));
	else if (flags.conv == 'x' || flags.conv == 'X')
		ft_putcount_hex(va_arg(args, unsigned int), (flags.conv == 'X'), count);
	else if (flags.conv == '%')
		(*count) += ft_putcount_chr('%', flags);
	else if (flags.conv == 'u')
		ft_putcount_dec((unsigned long)va_arg(args, unsigned int), count);
	return (flags.format_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;
	t_flags	flags;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] && i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			flags = parse_flags(&(format[i + 1]), "cspdixXu%", args);
			i += (process_format(&count, flags, args) + 1);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
