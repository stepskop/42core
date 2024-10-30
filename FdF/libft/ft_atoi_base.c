/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:57:48 by username          #+#    #+#             */
/*   Updated: 2024/10/30 16:58:43 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_base(char c, unsigned int base)
{
	char			*base_str;
	unsigned int	i;

	i = -1;
	base_str = "0123456789ABCDEF";
	while (++i < base && base_str[i])
	{
		if (base_str[i] == c)
			return (i);
		else if ((base_str[i] >= 65 && base_str[i] <= 90) && \
			base_str[i] + 32 == c)
			return (i);
	}
	return (-1);
}

int	ft_atoi_base(const char *nptr, unsigned int base)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (is_base(nptr[i], base) != -1)
	{
		res = (res * base) + is_base(nptr[i], base);
		i++;
	}
	return (res * sign);
}
