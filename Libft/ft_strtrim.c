/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:09:09 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/18 11:11:27 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trimable(char c, char const *set)
{
	unsigned int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	start = 0;
	while (s1[start] && is_trimable(s1[start], set))
		start++;
	len = ft_strlen(s1) - start;
	while (len > 0 && is_trimable((s1 + start)[len - 1], set))
		len--;
	return (ft_substr(s1, start, len));
}
