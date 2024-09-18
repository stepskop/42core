/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:54:16 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/18 11:10:17 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	int		i;
	size_t	wcount;

	i = 0;
	wcount = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			wcount++;
		i++;
	}
	return (wcount);
}

char	**ft_split(char const *s, char c)
{
	char			**splitted;
	size_t			current_word;
	unsigned int	i;
	size_t			j;

	i = 0;
	current_word = 0;
	splitted = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			splitted[current_word] = ft_substr(s, i, j);
			current_word++;
			i += j;
		}
		else
			i++;
	}
	splitted[current_word] = 0;
	return (splitted);
}
