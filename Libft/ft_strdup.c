/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:22:44 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/18 11:15:14 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*ptr;

	str_len = ft_strlen(s);
	ptr = malloc((str_len * sizeof(char)) + 1);
	if (!ptr)
		return (ptr);
	ptr[str_len] = '\0';
	while (str_len-- > 0)
		ptr[str_len] = s[str_len];
	return (ptr);
}
