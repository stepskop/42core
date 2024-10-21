/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:54:25 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/19 18:28:04 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*mut;
	int		s_len;

	mut = (char *)s;
	s_len = ft_strlen(s);
	while (mut[s_len] != (char)c)
	{
		if (s_len-- == 0)
			return (0);
	}
	return (mut + s_len);
}
