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

#include "ft_printf.h"

static int	process_format(int *count, t_flags flags, va_list args)
{
	if (flags.conv == 'c')
		(*count) += print_chr(va_arg(args, int), flags);
	else if (flags.conv == 's')
		(*count) += print_str(va_arg(args, char *), flags);
	else if (flags.conv == 'p')
		(*count) += print_ptr(va_arg(args, void *), flags);
	else if (flags.conv == 'd' || flags.conv == 'i')
		(*count) += print_nbr(va_arg(args, int), flags);
	else if (flags.conv == 'x')
		(*count) += print_hex(va_arg(args, unsigned int), 0, flags);
	else if (flags.conv == 'X')
		(*count) += print_hex(va_arg(args, unsigned int), 1, flags);
	else if (flags.conv == '%')
		(*count) += print_chr('%', flags);
	else if (flags.conv == 'u')
		(*count) += print_udc((unsigned long)va_arg(args, unsigned int), flags);
	return (flags.format_len);
}

static int	is_validopt(const char *str)
{
	char	*convs;
	char	*flags;
	char	*rest;
	int		i;
	int		is_prec;

	is_prec = 0;
	convs = "cspdixXu%";
	flags = "-+ #0*";
	rest = ".*0123456789";
	i = 0;
	while (ft_strchr(flags, str[i]))
		i++;
	while (ft_strchr(rest, str[i]))
	{
		if (str[i] == '.')
			is_prec++;
		if (is_prec > 1)
			return (0);
		i++;
	}
	if (ft_strchr(convs, str[i]))
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;
	t_flags	flags;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] && i < ft_strlen(format))
	{
		if (format[i] == '%' && is_validopt(&(format[i + 1])))
		{
			flags = parse_flags(&(format[i + 1]), "cspdixXu%", args);
			i += (process_format(&count, flags, args) + 1);
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
