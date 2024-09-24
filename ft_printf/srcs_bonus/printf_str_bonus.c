/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:51:46 by username          #+#    #+#             */
/*   Updated: 2024/09/24 10:54:11 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

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
	while (s[count] && count < precision)
		ft_putchar_fd(s[count++], 1);
	return (count);
}

int	print_str(char *s, t_flags flags)
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
