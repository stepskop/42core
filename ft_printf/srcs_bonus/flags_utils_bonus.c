/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:30:41 by username          #+#    #+#             */
/*   Updated: 2024/09/24 11:09:38 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

int	is_flag(char c)
{
	char	*flag_chars;

	flag_chars = "#-+0 ";
	while (*flag_chars)
	{
		if (c == *flag_chars++)
			return (1);
	}
	return (0);
}

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.plus = 0;
	flags.zero = 0;
	flags.h_tag = 0;
	flags.minus = 0;
	flags.space = 0;
	flags.width = 0;
	flags.precision = -1;
	return (flags);
}

void	set_option(char c, t_flags *flags)
{
	if (c == '#')
		flags->h_tag = 1;
	else if (c == '0' && !flags->minus)
		flags->zero = 1;
	else if (c == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	else if (c == ' ' && !flags->plus)
		flags->space = 1;
	else if (c == '+')
	{
		flags->space = 0;
		flags->plus = 1;
	}
}

size_t	set_modifs(const char *format, va_list args, t_flags *flags)
{
	size_t	i;

	i = 0;
	if (format[i] == '*')
		flags->width = va_arg(args, int);
	if (format[i] == '*')
		i++;
	else if (ft_isdigit(format[i]))
		flags->width = ft_atoi(&(format[i]));
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			flags->precision = va_arg(args, int);
			i++;
		}
		else
			flags->precision = ft_atoi(&(format[i]));
		while (ft_isdigit(format[i]))
			i++;
	}
	return (i);
}
