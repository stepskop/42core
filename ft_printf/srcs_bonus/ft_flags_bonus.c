/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:02:21 by username          #+#    #+#             */
/*   Updated: 2024/09/23 21:51:04 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

static int	is_flag(char c)
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

static t_flags	init_flags(void)
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

static void	set_option(char c, t_flags *flags)
{
	char	*flag_chars;

	flag_chars = "#-+0 ";
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

static size_t	set_modifs(const char *format, va_list args, t_flags *flags)
{
	size_t	i;

	i = 0;
	if (format[i] == '*')
	{
		flags->width = ft_atoi(va_arg(args, char *));
		i++;
	}
	else if (ft_isdigit(format[i]))
		flags->width = ft_atoi(&(format[i]));
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			flags->precision = ft_atoi(va_arg(args, char *));
			i++;
		}
		else if (ft_isdigit(format[i]))
			flags->precision = ft_atoi(&(format[i]));
		while (ft_isdigit(format[i]))
			i++;
	}
	return (i);
}

t_flags	parse_flags(const char *format, const char *convs, va_list args)
{
	t_flags	flags;
	size_t	i;
	size_t	j;

	i = 0;
	flags = init_flags();
	while (is_flag(format[i]))
		set_option(format[i++], &flags);
	i += set_modifs(&(format[i]), args, &flags);
	j = -1;
	while (convs[++j])
	{
		if (format[i] == convs[j])
			flags.conv = convs[j];
	}
	flags.format_len = i + 1;
	return (flags);
}
