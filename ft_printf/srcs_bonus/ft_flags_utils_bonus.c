/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:30:41 by username          #+#    #+#             */
/*   Updated: 2024/09/23 21:36:19 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

int	pad(int size, int zero)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (size < 0)
		return (0);
	return (size);
}
