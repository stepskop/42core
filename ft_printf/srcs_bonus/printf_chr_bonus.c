/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_chr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:51:13 by username          #+#    #+#             */
/*   Updated: 2024/09/24 10:53:56 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

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
