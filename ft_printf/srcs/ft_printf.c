/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:02:49 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/21 21:09:13 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

static int	process_format(char conv, int *count, va_list args)
{
	if (conv == 'c')
		(*count) += ft_putcount_chr(va_arg(args, int));
	else if (conv == 's')
		(*count) += ft_putcount_str(va_arg(args, char *));
	else if (conv == 'p')
		print_pointer(va_arg(args, void *), count);
	else if (conv == 'd' || conv == 'i')
		(*count) += ft_putcount_nbr(va_arg(args, int));
	else if (conv == 'x' || conv == 'X')
		ft_putcount_hex(va_arg(args, unsigned int), (conv == 'X'), count);
	else if (conv == '%')
		(*count) += ft_putcount_chr('%');
	else if (conv == 'u')
		ft_putcount_dec((unsigned long)va_arg(args, unsigned int), count);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] && i < ft_strlen(format))
	{
		if (format[i] == '%')
			i += (process_format(format[i + 1], &count, args) + 1);
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
