/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:54:16 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/19 18:47:06 by sskopek          ###   ########.fr       */
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

static void	*error_free(size_t current_word, char **splitted)
{
	while (current_word > 0)
		free(splitted[current_word--]);
	return ((void *)0);
}

static size_t	get_word_len(char const *s, size_t i, char c)
{
	size_t	j;

	j = 0;
	while (s[i + j] && s[i + j] != c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char			**splitted;
	size_t			current_word;
	size_t			i;
	size_t			j;

	i = 0;
	current_word = 0;
	splitted = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!splitted)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = get_word_len(s, i, c);
			splitted[current_word] = ft_substr(s, i, j);
			if (!splitted[current_word++])
				return (error_free(current_word - 1, splitted));
			i += j;
		}
		else
			i++;
	}
	splitted[current_word] = 0;
	return (splitted);
}
