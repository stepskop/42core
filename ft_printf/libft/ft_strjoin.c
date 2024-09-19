/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:25:59 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/18 11:11:15 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = malloc(((s1_len + s2_len + 1) * sizeof(char)));
	if (!dst)
		return ((void *)0);
	ft_strlcpy((dst + ft_strlcpy(dst, s1, s1_len + 1)), s2, s2_len + 1);
	return (dst);
}
