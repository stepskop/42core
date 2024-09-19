/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:53:03 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/18 19:45:34 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (!s)
		return ((void *)0);
	if (len > str_len)
		len = str_len;
	if (start >= str_len)
	{
		dst = malloc((size_t)1 * sizeof(char));
		if (!dst)
			return ((void *)0);
		dst[0] = '\0';
		return (dst);
	}
	dst = malloc((size_t)(len + 1) * sizeof(char));
	if (!dst)
		return ((void *)0);
	ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}
