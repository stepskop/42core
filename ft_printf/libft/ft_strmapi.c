/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:50:45 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/18 11:57:09 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = -1;
	dst = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dst)
		return ((void *)0);
	while (s[++i])
		dst[i] = f(i, s[i]);
	dst[i] = '\0';
	return (dst);
}
