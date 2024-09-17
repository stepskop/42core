/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:53:03 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/17 16:51:36 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return ((void *)0);
	ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}
