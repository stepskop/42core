/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_udc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:08:02 by username          #+#    #+#             */
/*   Updated: 2024/09/26 21:25:34 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

static int	print_pre(unsigned long ulong, int base_count, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += pad(flags.precision - base_count, 1);
	putdec(ulong);
	return (count);
}

int	print_udc(unsigned long ulong, t_flags flags)
{
	int	count;
	int	base_count;

	count = get_digits(ulong, 10);
	if (flags.precision == 0 && ulong == 0)
		count--;
	base_count = count;
	if (flags.minus && !(flags.precision == 0 && ulong == 0))
		count += print_pre(ulong, base_count, flags);
	if (flags.precision >= 0)
	{
		if (flags.precision < count)
			count += pad((flags.width - count), 0);
		else
			count += pad((flags.width - flags.precision), 0);
	}
	else
		count += pad(flags.width - count, flags.zero);
	if (!flags.minus && !(flags.precision == 0 && ulong == 0))
		count += print_pre(ulong, base_count, flags);
	return (count);
}
