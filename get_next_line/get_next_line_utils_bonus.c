/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:42:46 by username          #+#    #+#             */
/*   Updated: 2024/10/01 17:06:27 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*mut;

	mut = (char *)s;
	while (*mut != (char)c)
	{
		if (!*mut++)
			return (0);
	}
	return (mut);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size < 1)
		return (src_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;

	s1_len = 0;
	s2_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	dst = malloc(((s1_len + s2_len + 1) * sizeof(char)));
	if (!dst)
		return (NULL);
	ft_strlcpy((dst + ft_strlcpy(dst, s1, s1_len + 1)), s2, s2_len + 1);
	return (dst);
}

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
