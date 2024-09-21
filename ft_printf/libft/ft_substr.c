/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:53:03 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/19 19:04:10 by sskopek          ###   ########.fr       */
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
	if (start > str_len)
	{
		dst = malloc(1 * sizeof(char));
		if (!dst)
			return ((void *)0);
		dst[0] = '\0';
		return (dst);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return ((void *)0);
	ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}
