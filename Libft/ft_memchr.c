/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:07:20 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/17 13:13:57 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mut;

	mut = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*mut == c)
			return (mut);
		mut++;
	}
	return (0);
}
